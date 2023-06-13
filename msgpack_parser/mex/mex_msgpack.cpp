/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/**
 * @file mex_msgpack.cpp
 * @author Embotech AG
 * @date 15 July 2020
 * @brief Facilities for translating between MsgPack buffers and MATLAB structs
 * */
#include "mex_msgpack.hpp"

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>

#include <msgpack.hpp>

typedef float float32_t;
typedef double float64_t;

/* --- DESERIALIZATION ------------------------------------------------------------------------------ */
namespace msgpack
{
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
{
    namespace adaptor
    {
    // Declarations
    // Declaration before definition to allow recursion

    template<>
    struct convert<matlab::data::Array>
    {
        msgpack::object const &operator()(msgpack::object const &o, matlab::data::Array &matlabArray) const;

    private:
        msgpack::object const &convertMsgpackArray(msgpack::object const &o,
                                                   matlab::data::Array &matlabArray) const;
    };

    // Definitions

    template<typename T>
    struct convert<matlab::data::TypedArray<T>>
    {
        msgpack::object const &operator()(msgpack::object const &o,
                                          matlab::data::TypedArray<T> &matlabArray) const
        {
            // Sanity check
            if (o.type != msgpack::type::ARRAY)
            {
                throw std::runtime_error(std::string("Internal Error in ") + __FILE__ + ":" +
                                         std::to_string(__LINE__));
            }

            matlab::data::ArrayFactory arrayFactory;
            const auto arrayBegin = &o.via.array.ptr[0];
            const auto arrayEnd = &o.via.array.ptr[o.via.array.size];
            matlabArray = arrayFactory.createArray<T>({1, o.via.array.size});
            std::transform(arrayBegin, arrayEnd, matlabArray.begin(),
                           [](const msgpack::v2::object &elem) { return elem.as<T>(); });

            return o;
        }
    };

    template<>
    struct convert<matlab::data::StructArray>
    {
        /// Converts MsgPack map to Matlab struct
        /// Throws exception if keys are not strings
        msgpack::object const &operator()(msgpack::object const &o,
                                          matlab::data::StructArray &matlabArray) const
        {
            // Sanity check
            if (o.type != msgpack::type::MAP)
            {
                throw std::runtime_error(std::string("Internal Error in ") + __FILE__ + ":" +
                                         std::to_string(__LINE__));
            }

            // Gather keys (struct fields)
            const auto beginMap = &o.via.map.ptr[0];
            const auto endMap = &o.via.map.ptr[o.via.map.size];
            std::vector<std::string> keys;
            try
            {
                std::transform(beginMap, endMap, std::back_inserter(keys),
                               [](const msgpack::v1::object_kv &mapElem) {
                                   return mapElem.key.as<std::string>();
                               });
            }
            catch (const msgpack::type_error &e)
            {
                throw e;
            }

            matlab::data::ArrayFactory arrayFactory;
            matlabArray = arrayFactory.createStructArray({1, 1}, keys);
            for (uint32_t i = 0U; i < o.via.map.size; ++i)
            {
                const msgpack::v1::object_kv &mapElem = o.via.map.ptr[i];
                matlab::data::Array fieldValue;
                convert<matlab::data::Array>{}(mapElem.val, fieldValue);
                matlabArray[0][keys[i]] = fieldValue;
            }
            return o;
        }
    };

    msgpack::object const &convert<matlab::data::Array>::operator()(msgpack::object const &o,
                                                                    matlab::data::Array &matlabArray) const
    {
        matlab::data::ArrayFactory arrayFactory;
        switch (o.type)
        {
            case msgpack::type::NIL:
                matlabArray = arrayFactory.createEmptyArray();
                break;
            case msgpack::type::BOOLEAN:
                matlabArray = arrayFactory.createScalar(o.as<bool>());
                break;
            case msgpack::type::POSITIVE_INTEGER:
                matlabArray = arrayFactory.createScalar(o.as<uint64_t>());
                break;
            case msgpack::type::NEGATIVE_INTEGER:
                matlabArray = arrayFactory.createScalar(o.as<int64_t>());
                break;
            case msgpack::type::FLOAT32:
                matlabArray = arrayFactory.createScalar(o.as<float32_t>());
                break;
            case msgpack::type::FLOAT64:
                matlabArray = arrayFactory.createScalar(o.as<float64_t>());
                break;
            case msgpack::type::STR:
                matlabArray = arrayFactory.createCharArray(o.as<std::string>());
                break;
            case msgpack::type::ARRAY:
                this->convertMsgpackArray(o, matlabArray);
                break;
            case msgpack::type::MAP:
                convert<matlab::data::StructArray>{}(o,
                                                     static_cast<matlab::data::StructArray &>(matlabArray));
                break;
            case msgpack::type::BIN:
                throw msgpack::type_error();
                break;
            case msgpack::type::EXT:
                throw msgpack::type_error();
                break;
            default:
                throw std::runtime_error(std::string("Internal Error in ") + __FILE__ + ":" +
                                         std::to_string(__LINE__));
        }

        return o;
    }

    msgpack::object const &
    convert<matlab::data::Array>::convertMsgpackArray(msgpack::object const &o,
                                                      matlab::data::Array &matlabArray) const
    {
        // Sanity check
        if (o.type != msgpack::type::ARRAY)
        {
            throw std::runtime_error(std::string("Internal Error in ") + __FILE__ + ":" +
                                     std::to_string(__LINE__));
        }

        matlab::data::ArrayFactory arrayFactory;

        // Only continue if array has elements
        if (o.via.map.size == 0U)
        {
            matlabArray = arrayFactory.createEmptyArray();
            return o;
        }

        // Check if all the elements have the same type
        msgpack::type::object_type firstType = o.via.array.ptr[0].type;
        const auto arrayBegin = &o.via.array.ptr[0];
        const auto arrayEnd = &o.via.array.ptr[o.via.array.size];
        bool sameType = std::all_of(arrayBegin, arrayEnd, [&firstType](const msgpack::v2::object &elem) {
            return elem.type == firstType;
        });
        if (sameType)
        {
            switch (firstType)
            {
                case msgpack::type::NIL:
                    matlabArray = arrayFactory.createEmptyArray();
                    break;
                case msgpack::type::BOOLEAN:
                    convert<matlab::data::TypedArray<bool>>{}(
                        o, static_cast<matlab::data::TypedArray<bool> &>(matlabArray));
                    break;
                case msgpack::type::POSITIVE_INTEGER:
                    convert<matlab::data::TypedArray<uint64_t>>{}(
                        o, static_cast<matlab::data::TypedArray<uint64_t> &>(matlabArray));
                    break;
                case msgpack::type::NEGATIVE_INTEGER:
                    convert<matlab::data::TypedArray<int64_t>>{}(
                        o, static_cast<matlab::data::TypedArray<int64_t> &>(matlabArray));
                    break;
                case msgpack::type::FLOAT32:
                    convert<matlab::data::TypedArray<float32_t>>{}(
                        o, static_cast<matlab::data::TypedArray<float32_t> &>(matlabArray));
                    break;
                case msgpack::type::FLOAT64:
                    convert<matlab::data::TypedArray<float64_t>>{}(
                        o, static_cast<matlab::data::TypedArray<float64_t> &>(matlabArray));
                    break;
                case msgpack::type::STR:
                    // Create cell array of strings
                    convert<matlab::data::CellArray>{}(o,
                                                       static_cast<matlab::data::CellArray &>(matlabArray));
                    break;
                case msgpack::type::ARRAY:
                    convert<matlab::data::CellArray>{}(o,
                                                       static_cast<matlab::data::CellArray &>(matlabArray));
                    break;
                case msgpack::type::MAP:
                    convert<matlab::data::CellArray>{}(o,
                                                       static_cast<matlab::data::CellArray &>(matlabArray));
                    break;
                case msgpack::type::BIN:
                    throw msgpack::type_error();
                    break;
                case msgpack::type::EXT:
                    throw msgpack::type_error();
                    break;
                default:
                    throw std::runtime_error(std::string("Internal Error in ") + __FILE__ + ":" +
                                             std::to_string(__LINE__));
            }
        }
        else
        {
            // Array elements do not have the same type --> return cell array
            // CellArray is defined as TypedArray<matlab::data::Array>, we can reuse our array conversion
            // function.
            convert<matlab::data::CellArray>{}(o, static_cast<matlab::data::CellArray &>(matlabArray));
        }
        return o;
    }

    } // namespace adaptor
}
} // namespace msgpack

// Deserialize, this is fairly trivial with the visitor class defined earlier
MsgPackToMATLABParseStatus msgpackToMatlabstruct(const std::vector<char> &buffer,
                                                 std::size_t &offset,
                                                 std::shared_ptr<matlab::engine::MATLABEngine> matlabEngine,
                                                 matlab::data::Array &output)
{
    matlab::data::ArrayFactory factory;
    msgpack::object_handle result;

    try
    {
        msgpack::v2::unpack(result, buffer.data(), buffer.size(), offset);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return MsgPackToMATLABParseStatus::MsgPackError;
    }
    try
    {
        // Get msgpack::object from msgpack::object_handle (shallow copy)
        msgpack::object obj(result.get());
        msgpack::v3::adaptor::convert<matlab::data::Array>{}(obj, output);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return MsgPackToMATLABParseStatus::MATLABError;
    }

    return MsgPackToMATLABParseStatus::OK;
}

/* --- SERIALIZATION -------------------------------------------------------------------------------- */
// This is the msgpack approach of just defining how individual fields should get
// packed. This means one has to define how containers are iterated over and how
// primitive types are to be packed.
namespace msgpack
{
MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
{
    namespace adaptor
    {
    template<>
    struct pack<matlab::data::Array>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            matlab::data::Array const &value) const
        {
            // In case we got a struct, cache the fields because we can't ask
            // an individual struct for its fields anymore *sigh*
            std::vector<std::string> fieldNames;
            if (value.getType() == matlab::data::ArrayType::STRUCT)
            {
                for (const auto &name : static_cast<matlab::data::StructArray>(value).getFieldNames())
                {
                    fieldNames.push_back(name);
                }
            }

            // Get the dimensions and iterate over them
            const auto dims = value.getDimensions();
            if (dims[0] > 1)
            {
                packer.pack_array(dims[0]);
            }
            for (std::size_t i1 = 0; i1 < dims[0]; i1++)
            {
                if (dims[1] > 1)
                {
                    packer.pack_array(dims[1]);
                }
                for (std::size_t i2 = 0; i2 < dims[1]; i2++)
                {
                    switch (value.getType())
                    {
                        case matlab::data::ArrayType::DOUBLE:
                            packer << static_cast<double>(value[i1][i2]);
                            break;
                        case matlab::data::ArrayType::LOGICAL:
                            packer << static_cast<bool>(value[i1][i2]);
                            break;
                        case matlab::data::ArrayType::CHAR:
                            // Add a scope block so we can create variables
                            {
                                // This is a narrowing cast and should be avoided if possible
                                std::string tmp{static_cast<char>((static_cast<char16_t>(value[i1][i2])))};
                                packer << tmp;
                            }
                            break;
                        case matlab::data::ArrayType::INT8:
                            packer << (int8_t) value[i1][i2];
                            break;
                        case matlab::data::ArrayType::UINT8:
                            packer << static_cast<uint8_t>(value[i1][i2]);
                            break;
                        case matlab::data::ArrayType::INT16:
                            packer << static_cast<int16_t>(value[i1][i2]);
                            break;
                        case matlab::data::ArrayType::UINT16:
                            packer << static_cast<uint16_t>(value[i1][i2]);
                            break;
                        case matlab::data::ArrayType::INT32:
                            packer << static_cast<int32_t>(value[i1][i2]);
                            break;
                        case matlab::data::ArrayType::UINT32:
                            packer << static_cast<uint32_t>(value[i1][i2]);
                            break;
                        case matlab::data::ArrayType::INT64:
                            packer << static_cast<int64_t>(value[i1][i2]);
                            break;
                        case matlab::data::ArrayType::UINT64:
                            packer << static_cast<uint64_t>(value[i1][i2]);
                            break;
                        case matlab::data::ArrayType::STRUCT:
                            // Add a scope block so we can create variables
                            {
                                const matlab::data::StructArray arr = value;
                                packer.pack_map(fieldNames.size());
                                for (const auto &name : fieldNames)
                                {
                                    packer << std::string{name};
                                    matlab::data::Array fieldValue = value[i1][i2][name];
                                    packer << fieldValue;
                                }
                            }
                            break;
                        case matlab::data::ArrayType::CELL:
                            // Add a scope block so we can create variables
                            {
                                const matlab::data::CellArray arr = value;
                                matlab::data::Array fieldValue = value[i1][i2];
                                packer << fieldValue;
                            }
                            break;
                        default:
                            // At this point it's a bit difficult to give a better error
                            // message because we don't have the field name here and getType()
                            // is not directly printable *sigh*
                            std::string error_message = "Don't know how to pack field";
                            throw std::runtime_error(error_message);
                    }
                }
            }
            return packer;
        }
    };

    } // namespace adaptor
}
} // namespace msgpack

bool matlabstructToMsgpack(const matlab::data::Array &object,
                           std::shared_ptr<matlab::engine::MATLABEngine> matlabEngine,
                           std::vector<char> &output)
{
    // Create a matlab object factory to use for various purposes
    matlab::data::ArrayFactory factory;

    // Create a buffer to write things into
    msgpack::sbuffer buffer;
    msgpack::packer<msgpack::sbuffer> packer(&buffer);

    // Serialize the struct into the buffer, this uses the adaptor template
    try
    {
        packer << object;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return false;
    }

    output.clear();
    output.assign(buffer.data(), buffer.data() + buffer.size());

    return true;
}
