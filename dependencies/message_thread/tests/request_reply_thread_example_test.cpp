/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file request_reply_thread_example_test.cpp
/// @author embotech AG
/// @date 14 Jul 2020
/// @brief Example to illustrate how the MessageThread implementation can be used for a request/reply pattern.

#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <utility>

#include <gtest/gtest.h>

#include "message_thread.hpp"
#include "request_reply_broker.hpp"
#include "request_reply_message.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// A request/reply thread is a normal message thread (see message_thread_example_test.cpp) that uses
// embo::RequestReplyMessage objects. Instead of process(), the processor has to implement processRequest()
// for these messages.
//
// The example below implements a simple database thread. Users can insert entries using a simple payload
// message. Queries are done with a QueryRequest, a embo::RequestReplyMessage. Replies are received by a
// RequestReplyBroker, which allows users to (non-busily) wait for replies and can buffer them.

// Declaration of message types
struct InsertPayload;
struct QueryRequest;

using QueryReply = std::string;

// Declaration of message processor

/// @brief Message processor implementing database interface
class DatabaseProcessor
{
public:
    DatabaseProcessor();

    void process(const InsertPayload *msg);
    std::unique_ptr<QueryReply> processRequest(const QueryRequest *msg);

private:
    std::map<int32_t, std::string> m_database;
};

// Extend from embo::Message to define a normal payload message without reply.

struct InsertPayload : public embo::Message<DatabaseProcessor>
{
    explicit InsertPayload(int32_t key, std::string value) : m_key(key), m_value(std::move(value))
    {
    }

    void process(DatabaseProcessor *processor) const override
    {
        processor->process(this);
    }

    int32_t m_key;
    std::string m_value;
};

// Extend from embo::RequestReplyMessage if you need a reply from a request.

/// @brief Query request need a reply -> extend RequestReplyMessage
/// Callback will be set by RequestReplyBroker, no need to initialise it here.
struct QueryRequest : public embo::RequestReplyMessage<DatabaseProcessor, std::string>
{
    explicit QueryRequest(int32_t key) : m_key(key)
    {
    }

    std::unique_ptr<QueryReply> processRequest(DatabaseProcessor *processor) const override
    {
        return processor->processRequest(this);
    }

    int32_t m_key;
};

// Definition of the processor member functions

DatabaseProcessor::DatabaseProcessor() : m_database()
{
}

void DatabaseProcessor::process(const InsertPayload *msg)
{
    std::cout << "Inserting (" << msg->m_key << ", " << msg->m_value << ")" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    m_database.insert(std::make_pair(msg->m_key, msg->m_value));
}

std::unique_ptr<QueryReply> DatabaseProcessor::processRequest(const QueryRequest *msg)
{
    std::cout << "Received request for #" << msg->m_key << "." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));

    std::unique_ptr<QueryReply> reply;
    if (m_database.count(msg->m_key) > 0)
    {
        reply = std::make_unique<QueryReply>(m_database.at(msg->m_key));
    }
    else
    {
        reply = std::make_unique<QueryReply>("NOT-FOUND");
    }
    return reply;
}

/// @brief Owns a message thread object.
class ExampleDatabaseThreadOwner
{
public:
    ExampleDatabaseThreadOwner() : m_messageThread()
    {
        auto messageProcessor = std::make_unique<DatabaseProcessor>();
        m_messageThread = std::make_unique<embo::MessageThread<DatabaseProcessor>>(
            std::move(messageProcessor));
        m_messageThread->start();
    }

    /// @brief Send message to message thread
    void postMessage(std::unique_ptr<embo::Message<DatabaseProcessor>> msg)
    {
        m_messageThread->postMessage(std::move(msg));
    }

    /// @brief Get weak pointer to message thread
    /// The weak pointer is non-owning, i.e. it will be set to nullptr if the thread is destroyed.
    std::weak_ptr<embo::MessageThread<DatabaseProcessor>> getMessageThread()
    {
        return m_messageThread;
    }

private:
    std::shared_ptr<embo::MessageThread<DatabaseProcessor>> m_messageThread;
};

TEST(RequestReplyThreadTestSuite, requestReplyThreadDatabaseExampleTest)
{
    ExampleDatabaseThreadOwner msgThread{};

    // Send INSERT message to database
    msgThread.postMessage(std::make_unique<InsertPayload>(3, "The third entry"));

    // Query database
    embo::RequestReplyBroker<DatabaseProcessor, QueryReply> queryBroker{msgThread.getMessageThread()};
    bool messageSent = queryBroker.postMessage(std::make_unique<QueryRequest>(3));
    ASSERT_TRUE(messageSent);
    EXPECT_FALSE(queryBroker.isReplyReady());

    // Wait for reply
    std::unique_ptr<QueryReply> queryResult = queryBroker.getReply();
    std::cout << "The answer is: '" << *queryResult << "'" << std::endl;
    EXPECT_EQ(*queryResult, "The third entry");
}

// Test trying to destroy a RequestReplyBroker before the answer has been received
TEST(RequestReplyThreadTestSuite, requestReplyBrokerDestructionTest)
{
    ExampleDatabaseThreadOwner msgThread{};

    // Send INSERT message to database
    msgThread.postMessage(std::make_unique<InsertPayload>(3, "The third entry"));

    // Query database
    embo::RequestReplyBroker<DatabaseProcessor, QueryReply> queryBroker{msgThread.getMessageThread()};
    bool messageSent = queryBroker.postMessage(std::make_unique<QueryRequest>(3));
    ASSERT_TRUE(messageSent);
    EXPECT_FALSE(queryBroker.isReplyReady());

    // Broker is destroyed before the answer is received. This test makes sure that there is no segfault
    // in that case.
}
