/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/**
 * @file parse_msgpack_log_mex.cpp
 * @date 17 July 2019
 * @brief MEX function for parsing msgpack log files.
 *
 * The MEX function supports binary files containing an arbitrary number of msgpack maps in succession.
 * Other top-level object types are not supported. The maps themselves can of course contain other datatypes.
 * The function returns a single struct where all maps are assembled. All maps that have an element with
 * key "type" of the same value will be assembled together. All other maps will be put in a field called
 * "unknownType".
 *
 * Example:
 *
 * The following serialized objects (JSON instead of msgpack but you get what I mean)
 *
 *      {
 *          "type" : "init",
 *          "initialState" : [0.0, 0.3, 0.5]
 *      }
 *      {
 *          "type" : "getTrajectory",
 *          "currentState" : [0.0, 0.3, 0.5],
 *          "trajectory" : { "x" : [0.0, 1.0], "y" : [0.3, 2.0] }
 *      }
 *      {
 *          "type" : "getTrajectory",
 *          "currentState" : [0.2, 0.6, 1.5],
 *          "trajectory" : { "x" : [0.2, 1.0], "y" : [0.6, 2.0] }
 *      }
 *      {
 *          "random" : "void"
 *      }
 *
 * will be converted into a structure that is equivalent to
 *
 *      data.init.type = 'init';
 *      data.init.initialState = [0.0, 0.3, 0.5];
 *
 *      data.getTrajectory(1).type = 'getTrajectory';
 *      data.getTrajectory(1).currentState = [0.0, 0.3, 0.5];
 *      data.getTrajectory(1).trajectory.x = [0.0, 1.0];
 *      data.getTrajectory(1).trajectory.y = [0.3, 2.0];
 *
 *      data.getTrajectory(2).type = 'getTrajectory';
 *      data.getTrajectory(2).currentState = [0.2, 0.6, 1.5];
 *      data.getTrajectory(2).trajectory.x = [0.2, 1.0];
 *      data.getTrajectory(2).trajectory.y = [0.6, 2.0];
 *
 *      data.unknownType.random = 'void';
 */

#include <algorithm>
#include <exception>
#include <fstream>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <vector>

#include "mex_msgpack.hpp"

// mexAdapter.hpp has to be included as late as possible!
#include <mexAdapter.hpp>

// Definitions for MEX function arguments
static constexpr size_t N_IN_MIN = 1u; /**< Minimum number of input arguments. */
static constexpr size_t N_IN_MAX = 1u; /**< Maximum number of input arguments. */
static constexpr size_t IN_IDX_LOGFILE = 0u;

static constexpr size_t N_OUT_MAX = 1u; /**< Maximum number of output arguments. */
static constexpr size_t OUT_IDX_DATA = 0u;

typedef float float32_t;
typedef double float64_t;

class MexFunction : public matlab::mex::Function
{
public:
    void operator()(matlab::mex::ArgumentList outputs, matlab::mex::ArgumentList inputs) final
    {
        std::shared_ptr<matlab::engine::MATLABEngine> matlabEngine = getEngine();
        matlab::data::ArrayFactory factory;

        // Check inputs
        if (inputs.size() < N_IN_MIN || inputs.size() > N_IN_MAX)
        {
            // Incorrect number of inputs
            std::string errorMsg = "Expects between " + std::to_string(N_IN_MIN);
            errorMsg += " and ";
            errorMsg += std::to_string(N_IN_MAX);
            errorMsg += " inputs.";

            matlabEngine->feval(u"error", 0,
                                std::vector<matlab::data::Array>(
                                    {factory.createScalar("parseMsgPack:InputError"),
                                     factory.createScalar(errorMsg)}));
        }

        // Get log file name
        if (inputs[IN_IDX_LOGFILE].getType() != matlab::data::ArrayType::CHAR)
        {
            std::string errorMsg = "Input 1 needs to be a character array.";

            matlabEngine->feval(u"error", 0,
                                std::vector<matlab::data::Array>(
                                    {factory.createScalar("parseMsgPack:InputError"),
                                     factory.createScalar(errorMsg)}));
        }
        matlab::data::CharArray logFileName = inputs[0];

        // Copy content of log file
        std::ifstream logFile(logFileName.toAscii(), std::ios::binary | std::ios::ate);

        if (!logFile.is_open())
        {
            std::string errorMsg = "Could not open file '";
            errorMsg += logFileName.toAscii();
            errorMsg += "'.";

            matlabEngine->feval(u"error", 0,
                                std::vector<matlab::data::Array>(
                                    {factory.createScalar("parseMsgPack:InputError"),
                                     factory.createScalar(errorMsg)}));
        }

        // Copy data to msgpack buffer
        auto lengthLog = logFile.tellg();
        std::vector<char> buffer(lengthLog);
        logFile.seekg(0, std::ios::beg);
        logFile.read(buffer.data(), lengthLog);
        logFile.close();

        // Set up printing
        uint16_t numChars = 0u; // number of characters in last print command
        float64_t previousPercentage = -100.0;

        // Set up map that is going to be converted into data object later on
        std::set<std::string> allTypes;
        std::map<std::string, std::pair<std::set<std::string>, std::vector<matlab::data::StructArray>>> data;

        // Parse object after object
        std::size_t offset = 0;
        while (offset != buffer.size())
        {
            // Parse msgpack object
            matlab::data::Array object;
            auto parseSuccess = msgpackToMatlabstruct(buffer, offset, matlabEngine, object);
            if (parseSuccess != MsgPackToMATLABParseStatus::OK)
            {
                std::string warningMsg = "Parsing failed at offset ";
                warningMsg += std::to_string(offset);
                warningMsg += " because no object was present.";

                matlabEngine->feval(u"warning", 0,
                                    std::vector<matlab::data::Array>(
                                        {factory.createScalar("parseMsgPack:ParserWarning"),
                                         factory.createScalar(warningMsg)}));

                // If MsgPack parsing failed, we have to stop because we don't know how far to move to
                // the start of the next msgpack object.
                if (parseSuccess == MsgPackToMATLABParseStatus::MsgPackError)
                {
                    break;
                }
                else
                {
                    // If instead MATLAB struct creation failed, we can skip this msgpack entry and
                    // continue with the next.
                    continue;
                }
            }

            if (object.getType() != matlab::data::ArrayType::STRUCT)
            {
                std::string errorMsg = "Top-level objects need to be msgpack maps.";

                matlabEngine->feval(u"warning", 0,
                                    std::vector<matlab::data::Array>(
                                        {factory.createScalar("parseMsgPack:ParserWarning"),
                                         factory.createScalar(errorMsg)}));
                continue;
            }

            // Determine type of log entry
            // If it contains a field called "type" containing a string, take that
            // Otherwise, it is "unknownType".
            auto matlabStruct = (matlab::data::StructArray) object;
            auto fieldnames = matlabStruct.getFieldNames();
            std::string logTypeName = "unknownType";
            if (std::find(fieldnames.begin(), fieldnames.end(), std::string("type")) != fieldnames.end() &&
                matlabStruct[0]["type"].getType() == matlab::data::ArrayType::CHAR)
            {
                logTypeName = ((const matlab::data::CharArray &) matlabStruct[0]["type"]).toAscii();
            }

            if (data.count(logTypeName) == 0u)
            {
                data[logTypeName] = std::make_pair(std::set<std::string>(),
                                                   std::vector<matlab::data::StructArray>());
                allTypes.insert(logTypeName);
            }

            // Merge fieldnames
            data[logTypeName].first.insert(fieldnames.begin(), fieldnames.end());
            data[logTypeName].second.emplace_back(matlabStruct);

            // Print update every 1%
            float64_t percentage = 100.0 * offset / buffer.size();
            if (percentage >= previousPercentage + 1.0)
            {
                std::string msgUpdate(numChars, '\b');
                msgUpdate += "Processing... %5.0f%%";
                matlabEngine->feval(u"fprintf", 0,
                                    {factory.createScalar(msgUpdate), factory.createScalar(percentage)});
                numChars = 20u;
                previousPercentage = percentage;
            }
        }
        matlabEngine->feval(u"fprintf", 1, {factory.createScalar("\n")});

        // Convert C++ map data into a Matlab struct
        outputs[OUT_IDX_DATA] = factory.createStructArray({1, 1}, std::vector<std::string>(allTypes.begin(),
                                                                                           allTypes.end()));

        // Go through all entry types
        for (auto const &dataElement : data)
        {
            // Union of the fields of all log entries of this type
            const auto &fieldsDataElement = dataElement.second.first;
            // All log entries of this type
            const auto &logEntries = dataElement.second.second;

            auto tempStruct = factory.createStructArray({logEntries.size(), 1},
                                                        std::vector<std::string>(fieldsDataElement.begin(),
                                                                                 fieldsDataElement.end()));
            for (size_t i = 0; i < logEntries.size(); ++i)
            {
                // Note that each log entry could be missing some fields (we used the UNION of all fields
                // above) We have to go through all fields this entry has and copy its content to the combined
                // struct.
                auto const &logEntry = logEntries[i];
                auto fieldsLogEntry = logEntry.getFieldNames();
                for (auto const &field : fieldsLogEntry)
                {
                    // Create copy and assign (direct assignment fails to compile)
                    matlab::data::Array tempArray = logEntry[0][field];
                    tempStruct[i][field] = tempArray;
                }
            }
            outputs[OUT_IDX_DATA][0][dataElement.first] = tempStruct;
        }
    }
};
