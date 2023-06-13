/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file message_thread_example_test.cpp
/// @author embotech AG
/// @date 14 Jul 2020
/// @brief Example to illustrate MessageThread implementation.

#include <cstdint>
#include <iostream>
#include <memory>
#include <utility>

#include <gtest/gtest.h>

#include "message.hpp"
#include "message_thread.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// A message thread is defined by message types (implementation of embo::Message) and a message processor. The
// processor runs in a background thread and receives messages posted to the MessageThread object.
//
// The scenario below has three message types. ExampleProcessor can process all of them. It has an
// implementation of process() for each message type. Common logic needed for processing two different types
// is stored directly in the processor.

// Declaration of message types
struct SimplePayload;
struct ComplexPayload;
struct AlsoComplexPayload;

// Declaration of message processor

class ExampleProcessor
{
public:
    ExampleProcessor();

    void process(const SimplePayload *msg);
    void process(const ComplexPayload *msg);
    void process(const AlsoComplexPayload *msg);

private:
    int32_t m_counter;
};

// Definition of message types

struct SimplePayload : public embo::Message<ExampleProcessor>
{
    explicit SimplePayload(const int32_t simpleValue) : m_simpleValue(simpleValue)
    {
    }

    void process(ExampleProcessor *processor) const override
    {
        processor->process(this);
    }

    const int32_t m_simpleValue;
};

struct ComplexPayload : public embo::Message<ExampleProcessor>
{
    explicit ComplexPayload(const double complexValue) : m_complexValue(complexValue)
    {
    }

    void process(ExampleProcessor *processor) const override
    {
        processor->process(this);
    }

    const double m_complexValue;
};

struct AlsoComplexPayload : public embo::Message<ExampleProcessor>
{
    explicit AlsoComplexPayload(const double complexValue, const double anotherComplexValue)
        : m_complexValue(complexValue), m_anotherComplexValue(anotherComplexValue)
    {
    }

    void process(ExampleProcessor *processor) const override
    {
        processor->process(this);
    }

    const double m_complexValue;
    const double m_anotherComplexValue;
};

// Definition of the processor member functions

ExampleProcessor::ExampleProcessor() : m_counter(0)
{
}

void ExampleProcessor::process(const SimplePayload *msg)
{
    std::cout << "Simple message processed, contains " << msg->m_simpleValue << std::endl;
}

void ExampleProcessor::process(const ComplexPayload *msg)
{
    ++m_counter;
    std::cout << "Complex message processed, contains " << msg->m_complexValue << std::endl;
    std::cout << "Common logic counter: " << m_counter << std::endl;
}

void ExampleProcessor::process(const AlsoComplexPayload *msg)
{
    ++m_counter;
    std::cout << "AlsoComplex message processed, contains " << msg->m_complexValue << " "
              << msg->m_anotherComplexValue << std::endl;
    std::cout << "Common logic counter: " << m_counter << std::endl;
}

/// @brief Owns a message thread object.
class ExampleMsgThreadOwner
{
public:
    ExampleMsgThreadOwner() : m_messageThread()
    {
        auto messageProcessor = std::make_unique<ExampleProcessor>();
        m_messageThread = std::make_unique<embo::MessageThread<ExampleProcessor>>(
            std::move(messageProcessor));
        m_messageThread->start();
    }

    /// @brief Send message to message thread
    void postMessage(std::unique_ptr<embo::Message<ExampleProcessor>> msg)
    {
        m_messageThread->postMessage(std::move(msg));
    }

private:
    std::unique_ptr<embo::MessageThread<ExampleProcessor>> m_messageThread;
};

TEST(MessageThreadTestSuite, exampleMessageThreadTest)
{
    ExampleMsgThreadOwner msgThread{};

    // Send three messages with different types.
    auto simplePayload = std::make_unique<SimplePayload>(5);
    auto complexPayload = std::make_unique<ComplexPayload>(28.7533);
    auto alsoComplexPayload = std::make_unique<AlsoComplexPayload>(42.42, 43.43);
    msgThread.postMessage(std::move(simplePayload));
    msgThread.postMessage(std::move(complexPayload));
    msgThread.postMessage(std::move(alsoComplexPayload));
}

TEST(MessageThreadTestSuite, noStartTest)
{
    // Create a messageThread object but do not call start() method. This test asserts that the destructor
    // still works without issues in that case.
    auto messageThread = std::make_unique<embo::MessageThread<ExampleProcessor>>(
        std::make_unique<ExampleProcessor>());
}
