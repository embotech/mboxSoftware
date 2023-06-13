/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 9 Jun 2021
/// @brief Main program that configures and launches the mBox software.

#include <iostream>
#include <chrono>
#include <thread>
#include <condition_variable>

#include <obrttg.hpp>
#include <build_hash.hpp>

static obrttg::Obrttg obrttgObj{};
static bool exitFlag = false;

void signalHandler(int signum)
{
    std::cout << "[obrttg-sw] Received interrupt signal ( " << signum << " ). Exiting..." << std::endl;
    obrttgObj.terminate();
}

int main()
{
    std::cout << "[obrttg-sw] Build hash -- " << kBuildHash << std::endl;
    std::cout << "[obrttg-sw] Preliminary checks" << std::endl;
    std::cout << "[obrttg-sw]   Time synchronization ... " << std::flush;
    std::cout << "[OK]" << std::endl;

    // Configure Obrttg threads
    std::cout << "[obrttg-sw] Configuration" << std::endl;
    auto thrCfg = obrttgObj.getThreadConfig();
    // CPU affinity
    thrCfg.main.cpuSet = {0,1};
    thrCfg.otp.cpuSet = {2};
    thrCfg.comm.cpuSet = {3};
    // Thread scheduling policy
    thrCfg.main.policy = SCHED_FIFO;
    thrCfg.otp.policy = SCHED_FIFO;
    thrCfg.comm.policy = SCHED_FIFO;
    // Thread scheduling priority 
    thrCfg.main.priority = 99; // Max priority
    thrCfg.otp.priority = 99; // Max priority
    thrCfg.comm.priority = 99; // Max priority

    obrttgObj.setThreadConfig(thrCfg);

    // Initialize obrttg software
    std::cout << "[obrttg-sw]   initialize() ... ";
    if (obrttgObj.initialize())
    {
        std::cout << "[obrttg-sw]   initialize() ... [FAIL ( " << obrttgObj.status() << " )]" << std::endl;
    }
    else
    {
        std::cout << "[OK]" << std::endl;
    }

    // Launch obrttg software
    std::cout << "[obrttg-sw]   start() ... " << std::flush;
    if (obrttgObj.start())
    {
        std::cout << "[obrttg-sw]   start() ... [FAIL ( " << obrttgObj.status() << " )]" << std::endl;
    }
    else
    {
        std::cout << "[OK]" << std::endl;
    }

    std::cout << "[obrttg-sw] Execution" << std::endl;
    std::cout << "[obrttg-sw]   join() ... " << std::flush;

    // Wait for the mission to be completed
    obrttgObj.join();

    if (obrttgObj.status())
    {
        std::cout << "[obrttg-sw]  join() ... [FAIL ( " << obrttgObj.status() << " )]" << std::endl;
    }
    else
    {
        std::cout << "[OK]" << std::endl;
    }

    std::cout << "[obrttg-sw] Cleanup" << std::endl;
    // Cleanup obrttg software
    std::cout << "[obrttg-sw]   terminate() ... " << std::endl;
    obrttgObj.terminate();
    std::cout << "[obrttg-sw]   terminate() ... [OK]" << std::endl;

    return 0;
}
