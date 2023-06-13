/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author Embotech AG
/// @date 18 Jun 2020
/// @brief Declares msgpack wrapper structures for the log types defined in msgpack_pase_utils.hpp.

#ifndef _MBOX_LOGGING_INCLUDE_MSGPACK_WRAPPER_LOG_TYPES_HPP_
#define _MBOX_LOGGING_INCLUDE_MSGPACK_WRAPPER_LOG_TYPES_HPP_

#include <cstdint>

#include "msgpack.hpp"

#include "msgpack_parse_utils.hpp"
#include "msgpack_wrapper_obrttg_types.hpp"


namespace msgpack
{

/// The wrappers contained in this file were automatically generated using the itsawrap tool from libembotech.

MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
{
    namespace adaptor
    {

    template<>
    struct pack<obrttg::ObrttgLog>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            obrttg::ObrttgLog const &value) const
        {
            packer.pack_map(5u);
            packer << "timestamp" << value.timestamp;
            packer << "type" << "obrttg";
            packer << "navigation" << value.navigation;
            packer << "guidance" << value.guidance;
            packer << "mvm" << value.mvm;

            return packer;
        }
    };

    template<>
    struct pack<obrttg::OptimalTrajectoryPlannerLog>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            obrttg::OptimalTrajectoryPlannerLog const &value) const
        {
            packer.pack_map(3u);
            packer << "timestamp" << value.timestamp;
            packer << "type" << "otp";
            packer << "otp" << value.otp;

            return packer;
        }
    };

    template<>
    struct pack<obrttg::CommInLog>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            obrttg::CommInLog const &value) const
        {
            packer.pack_map(3u);
            packer << "timestamp" << value.timestamp;
            packer << "type" << "commIn";
            packer << "commIn" << value.commIn;

            return packer;
        }
    };

    template<>
    struct pack<obrttg::CommOutLog>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            obrttg::CommOutLog const &value) const
        {
            packer.pack_map(3u);
            packer << "timestamp" << value.timestamp;
            packer << "type" << "commOut";
            packer << "commOut" << value.commOut;

            return packer;
        }
    };

    }
}
}

#endif // #ifndef _MBOX_LOGGING_INCLUDE_MSGPACK_WRAPPER_LOG_TYPES_HPP_