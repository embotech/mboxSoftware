/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 18 Jun 2021
/// @brief Implementation of LogProcessor base class. It takes care of serializing log messages and writing them to the corresponding log file.

#include <chrono>
#include <ctime>

#include "log_processor.hpp"
#include <filesystem>

obrttg::LogProcessor::LogProcessor(std::unique_ptr<std::ostream> logFile)
    : logFile(std::move(logFile)), packer(this->logFile.get())
{}

//void obrttg::LogProcessor::process(const LogOptimalTrajectoryPlannerMessage *message)
//{
//    packer << message->log;
//
//    logFile->flush();
//}

int64_t obrttg::LogProcessor::getCurrentTimestamp()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::system_clock::now().time_since_epoch())
        .count();
}

std::string obrttg::LogProcessor::getLogFileName(const std::string &prefix)
{
    // Get date string
    time_t rawtime;
    struct tm *timeinfo;
    char timeString[80];

    // [TODO] Recover logging directory from parameter server?
    std::string logDir = "logs";
    if (!std::filesystem::is_directory(logDir) || !std::filesystem::exists(logDir)) 
    { 
        // Check if logs directory exists
        std::filesystem::create_directory(logDir); // create src folder
    }

    time(&rawtime);
    timeinfo = localtime(&rawtime); // NOLINT(runtime/threadsafe_fn) Thread-safe localtime_r() is not portable

    strftime(timeString, sizeof(timeString), "%Y%m%d_%H_%M_%S", timeinfo);

    std::string nameLogFile = logDir + "/";
    nameLogFile += timeString;
    nameLogFile += "_";
    nameLogFile += "log_";
    nameLogFile += prefix;
    nameLogFile += ".msgpack";

    return nameLogFile;
}