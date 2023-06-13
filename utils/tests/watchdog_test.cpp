/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 03 Nov 2021
/// @brief Unit tests for Watchdog class.

#include "watchdog.hpp"
#include "time_utils.hpp"

#include "gtest/gtest.h"

class WatchdogTestFixture : public ::testing::Test
{
public:
    WatchdogTestFixture() : m_myvar(0)
    {}

    ~WatchdogTestFixture()
    {
        m_watchdog.stop();
    }


protected:
    obrttg::Watchdog m_watchdog;
    int m_myvar;
    std::mutex m_mtx;

    void setVariable(int val)
    {
        std::unique_lock<std::mutex> lk(m_mtx);
        m_myvar = val;
    }

    int getVariable()
    {
        std::unique_lock<std::mutex> lk(m_mtx);
        return m_myvar;
    }

    void callbackFcn()
    {
        setVariable(m_myvar+1);
    }
};

TEST_F(WatchdogTestFixture, setDuration)
{
    // Set duration before starting the timer -> success
    ASSERT_EQ(m_watchdog.setDuration(10*1000), 0);
    // Start the timer -> success
    ASSERT_EQ(m_watchdog.start(), 0);
    // Set duration after starting the timer -> fail 
    ASSERT_EQ(m_watchdog.setDuration(10*1000), 1);
    // Stop the timer
    m_watchdog.stop();
    // Set duration after stoping the timer -> success 
    ASSERT_EQ(m_watchdog.setDuration(10*1000), 0);
}

TEST_F(WatchdogTestFixture, setCallback)
{
    // Set duration before starting the timer -> success
    ASSERT_EQ(m_watchdog.setDuration(10*1000), 0);
    // Set callback before starting the timer -> success
    ASSERT_EQ(m_watchdog.setCallback([](){/*Do nothing here */}), 0);
    // Start the timer -> success
    ASSERT_EQ(m_watchdog.start(), 0);
    // Set callback after starting the timer -> fail 
    ASSERT_EQ(m_watchdog.setCallback([](){/*Do nothing here */}), 1);
    // Stop the timer
    m_watchdog.stop();
    // Set callback after stoping the timer -> success
    ASSERT_EQ(m_watchdog.setCallback([](){/*Do nothing here */}), 0);

}

TEST_F(WatchdogTestFixture, start)
{
    // Watchdog timer not configured -> return error code (1)
    ASSERT_EQ(m_watchdog.start(), 1);

    // Watchdog timer configured -> return success code (0)
    m_watchdog.setDuration(5*1000);
    ASSERT_EQ(m_watchdog.start(), 0);

    // Watchdog start method called a second time after stopping-> return success code (0)
    m_watchdog.stop();    
    ASSERT_EQ(m_watchdog.start(), 0);

    // Watchdog start method called twice without stopping -> return error code (1)
    ASSERT_EQ(m_watchdog.start(), 1);

    m_watchdog.stop();
}

TEST_F(WatchdogTestFixture, stop)
{
    uint64_t dt = 50;   // Timer interval duration in ms
    m_watchdog.setDuration(dt*1000);
    m_watchdog.setCallback([this] () {this->setVariable(this->getVariable()+1);});
    // Start and stop before reaching timeout
    m_watchdog.start();
    obrttg::msleep(dt-10);
    m_watchdog.stop();
    // Variable value is the same
    ASSERT_EQ(getVariable(), 0);

    // Start and stop after reaching the first timeout
    m_watchdog.start();
    obrttg::msleep(dt+10);
    m_watchdog.stop();
    // Variable value increased by 1
    ASSERT_EQ(getVariable(), 1);

    // Start and stop after several timeouts
    m_watchdog.start();
    obrttg::msleep(5*dt+10);
    m_watchdog.stop();
    // Variable value increased by 1
    ASSERT_EQ(getVariable(), 2);
}

TEST_F(WatchdogTestFixture, pet_early)
{
    uint64_t dt = 50;   // Timer interval duration in ms
    int it = 20;
    m_watchdog.setDuration(dt*1000);
    m_watchdog.setCallback([this] () {this->setVariable(this->getVariable()+1);});

    // Pet the watchdog timer before reaching the timeout -> callback not executed -> variable value remains the same
    m_watchdog.start();
    for (int i = 0; i < it; i++) 
    {
        obrttg::msleep(dt-10);
        // The value of the variable remains the same
        ASSERT_EQ(getVariable(), 0) << "Failed after " << i << " iterations.";
        m_watchdog.pet();
    }
    m_watchdog.stop();

    obrttg::msleep(dt*10);
    // The value of the variable remains the same after stopping
    ASSERT_EQ(getVariable(), 0);
}

TEST_F(WatchdogTestFixture, pet_late)
{

    uint64_t dt = 50;   // Timer interval duration in ms
    int it = 20;
    m_watchdog.setDuration(dt*1000);
    m_watchdog.setCallback([this] () {this->setVariable(this->getVariable()+1);});

    // Pet the watchdog timer after reaching the timeout -> callback executed -> variable value increased
    m_watchdog.start();
    for (int i = 0; i < it; i++) 
    {
        obrttg::msleep(dt + 10);
        // The value of the variable has been incremented by 1
        ASSERT_EQ(getVariable(), i+1) << "Failed after " << i << " iterations.";
        m_watchdog.pet();
    }
    m_watchdog.stop();
    // The value of the variable remains the same after stopping
    ASSERT_EQ(getVariable(), it);

    // Don't reset the watchdog timer for several timeouts -> the variable value is only increased by one
    m_watchdog.start();
    obrttg::msleep(dt*10);
    m_watchdog.stop();
    ASSERT_EQ(getVariable(), it+1);
}