/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

#ifndef MEX_MSGPACK_HPP
#define MEX_MSGPACK_HPP
/* Library implementing MsgPack buffer <-> Matlab struct translations */

#include <memory>
#include <vector>

#include <MatlabDataArray.hpp>
#include <cppmex/mexMatlabEngine.hpp>

/* @brief Enum class to represent the result status of a msgpack to matlab struct operation */
enum class MsgPackToMATLABParseStatus
{
    /** Everything went well */
    OK,

    /** A problem occurred in MsgPack unpacking */
    MsgPackError,

    /** A problem occurred in the transformation of the MsgPack buffer to a MATLAB object */
    MATLABError
};

/* @brief Turn a given msgpack buffer into a matlab struct
 * @param[in] buffer Reference to the buffer to turn into a matlab object
 * @param[in] offset Reference to an offset number, this gets modified
 * @param[in] matlabEngine Matlab Engine to create the struct with
 * @param[out] output Mutable reference to where the created object should be stored
 * @return MsgPackToMATLABParseStatus describing the success or failure
 */
MsgPackToMATLABParseStatus msgpackToMatlabstruct(const std::vector<char> &buffer,
                                                 std::size_t &offset,
                                                 std::shared_ptr<matlab::engine::MATLABEngine> matlabEngine,
                                                 matlab::data::Array &output);

/* @brief Turn a given msgpack buffer into a matlab struct
 * @param[in] object Reference to the object to serialize to MsgPack
 * @param[in] matlabEngine Matlab Engine to create the struct with
 * @param[out] output Mutable reference to where the created object should be stored
 * @return true on success, false on failure
 */
bool matlabstructToMsgpack(const matlab::data::Array &object,
                           std::shared_ptr<matlab::engine::MATLABEngine> matlabEngine,
                           std::vector<char> &output);

#endif /* MEX_MSGPACK_HPP */
