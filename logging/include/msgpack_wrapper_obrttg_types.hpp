/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file msgpack_wrapper_obrttg_types.hpp
/// @author Embotech AG
/// @date 18 Jun 2020
/// @brief Declares msgpack wrapper structures for the Obrttg codegen types.

#ifndef _MBOX_LOGGING_INCLUDE_MSGPACK_WRAPPER_OBRTTG_TYPES_HPP_
#define _MBOX_LOGGING_INCLUDE_MSGPACK_WRAPPER_OBRTTG_TYPES_HPP_

#include <cstdint>
#include <map>
#include <string>

#include "msgpack.hpp"

#include "obrttg_types.hpp"

// Function definitions
namespace msgpack
{

/// The wrappers contained in this file were automatically generated using the itsawrap tool from libembotech.
///     - busMboxParameters
///     - busValidationOptions
///     - busGncParameters
///     - busGncCommIn
///     - busGncCommOut
///     - busGncGuidance
///     - busGncNavigation
///     - busGncController
///     - busGncOtp
///     - busGncMvm. 

MSGPACK_API_VERSION_NAMESPACE(MSGPACK_DEFAULT_API_NS)
{
    namespace adaptor
    {

    template<>
    struct pack<busMboxParameters>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            busMboxParameters const &value) const
        {
            size_t wp_size = MBOX_PARAMS_N_WAYPOINTS*MBOX_PARAMS_DIM_WAYPOINTS;
            packer.pack_map(9u);
            packer << "waypoints";
            packer.pack_array(wp_size);
            for( uint32_t k = 0; k < wp_size; ++k )
            {
                packer << value.waypoints[k];
            }
            packer << "takeOffHeight" << value.takeOffHeight;
            packer << "verticalTakeOffVelocity";
            packer.pack_array(3);
            for( uint32_t k = 0; k < 3; ++k )
            {
                packer << value.verticalTakeOffVelocity[k];
            }
            packer << "trackingErrorThreshold" << value.trackingErrorThreshold;
            packer << "maxSpeedConstraint" << value.maxSpeedConstraint;
            packer << "tiltAngleConstraint" << value.tiltAngleConstraint;
            packer << "glideSlopeAngleConstraint" << value.glideSlopeAngleConstraint;
            packer << "offlineOtpGeneration" << value.offlineOtpGeneration;
            packer << "launchPadPosition";
            packer.pack_array(3);
            for( uint32_t k = 0; k < 3; ++k )
            {
                packer << value.launchPadPosition[k];
            }
            return packer;
        }
    };

    template<>
    struct convert<busMboxParameters>
    {
        msgpack::object const &operator()(msgpack::object const &o, busMboxParameters &v) const
        {
            if (o.type != msgpack::type::MAP || o.via.map.size != 9u)
            {
                throw msgpack::type_error();
            }
            std::map<std::string, msgpack::object> vMap = o.as<std::map<std::string, msgpack::object>>();

            size_t wp_size = MBOX_PARAMS_N_WAYPOINTS*MBOX_PARAMS_DIM_WAYPOINTS;
            for( uint32_t k = 0; k < wp_size; ++k )
            {
                vMap.at("waypoints").via.array.ptr[k].convert(v.waypoints[k]);
            }

            vMap.at("takeOffHeight").convert(v.takeOffHeight);

            for( uint32_t k = 0; k < 3; ++k )
            {
                vMap.at("verticalTakeOffVelocity").via.array.ptr[k].convert(v.verticalTakeOffVelocity[k]);
            }
            vMap.at("trackingErrorThreshold").convert(v.trackingErrorThreshold);
            vMap.at("maxSpeedConstraint").convert(v.maxSpeedConstraint);
            vMap.at("tiltAngleConstraint").convert(v.tiltAngleConstraint);
            vMap.at("glideSlopeAngleConstraint").convert(v.glideSlopeAngleConstraint);
            vMap.at("offlineOtpGeneration").convert(v.offlineOtpGeneration);

            for( uint32_t k = 0; k < 3; ++k )
            {
                vMap.at("launchPadPosition").via.array.ptr[k].convert(v.launchPadPosition[k]);
            }
            return o;
        }
    };

    template<>
    struct pack<busValidationOptions>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            busValidationOptions const &value) const
        {
            packer.pack_map(1u);
            packer << "retargetingEventTime" << value.retargetingEventTime;
            return packer;
        }
    };

    template<>
    struct convert<busValidationOptions>
    {
        msgpack::object const &operator()(msgpack::object const &o, busValidationOptions &v) const
        {
            if (o.type != msgpack::type::MAP || o.via.map.size != 1u)
            {
                throw msgpack::type_error();
            }
            std::map<std::string, msgpack::object> vMap = o.as<std::map<std::string, msgpack::object>>();
            vMap.at("retargetingEventTime").convert(v.retargetingEventTime);
            return o;
        }
    };

    template<>
    struct pack<busGncParameters>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            busGncParameters const &value) const
        {
            packer.pack_map(2u);
            packer << "gncParameters" << value.gncParameters;
            packer << "validOptionParameters" << value.validOptionParameters;
            return packer;
        }
    };

    template<>
    struct convert<busGncParameters>
    {
        msgpack::object const &operator()(msgpack::object const &o, busGncParameters &v) const
        {
            if (o.type != msgpack::type::MAP || o.via.map.size != 2u)
            {
                throw msgpack::type_error();
            }
            std::map<std::string, msgpack::object> vMap = o.as<std::map<std::string, msgpack::object>>();
            vMap.at("gncParameters").convert(v.gncParameters);
            vMap.at("validOptionParameters").convert(v.validOptionParameters);
            return o;
        }
    };

    template<>
    struct pack<busGncCommIn>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            busGncCommIn const &value) const
        {
            packer.pack_map(5u);
            packer << "timestamp_obc" << value.timestamp_obc;
            packer << "timestamp" << value.timestamp;
            packer << "mission_status" << value.mission_status;
            packer << "vehicle_state";
            packer.pack_array(17);
            for( uint32_t k = 0; k < 17; ++k )
            {
                packer << value.vehicle_state[k];
            }
            packer << "engine_status";
            packer.pack_array(16);
            for( uint32_t k = 0; k < 16; ++k )
            {
                packer << value.engine_status[k];
            }
            return packer;
        }
    };

    template<>
    struct convert<busGncCommIn>
    {
        msgpack::object const &operator()(msgpack::object const &o, busGncCommIn &v) const
        {
            if (o.type != msgpack::type::MAP || o.via.map.size != 5u)
            {
                throw msgpack::type_error();
            }
            std::map<std::string, msgpack::object> vMap = o.as<std::map<std::string, msgpack::object>>();
            vMap.at("timestamp_obc").convert(v.timestamp_obc);
            vMap.at("timestamp").convert(v.timestamp);
            vMap.at("mission_status").convert(v.mission_status);

            for( uint32_t k = 0; k < 17; ++k )
            {
                vMap.at("vehicle_state").via.array.ptr[k].convert(v.vehicle_state[k]);
            }

            for( uint32_t k = 0; k < 16; ++k )
            {
                vMap.at("engine_status").via.array.ptr[k].convert(v.engine_status[k]);
            }
            return o;
        }
    };

    template<>
    struct pack<busGncCommOut>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            busGncCommOut const &value) const
        {
            packer.pack_map(4u);
            packer << "timestamp" << value.timestamp;
            packer << "pac_status" << value.pac_status;
            packer << "position_reference";
            packer.pack_array(3);
            for( uint32_t k = 0; k < 3; ++k )
            {
                packer << value.position_reference[k];
            }
            packer << "velocity_reference";
            packer.pack_array(3);
            for( uint32_t k = 0; k < 3; ++k )
            {
                packer << value.velocity_reference[k];
            }
            return packer;
        }
    };

    template<>
    struct convert<busGncCommOut>
    {
        msgpack::object const &operator()(msgpack::object const &o, busGncCommOut &v) const
        {
            if (o.type != msgpack::type::MAP || o.via.map.size != 4u)
            {
                throw msgpack::type_error();
            }
            std::map<std::string, msgpack::object> vMap = o.as<std::map<std::string, msgpack::object>>();
            vMap.at("timestamp").convert(v.timestamp);
            vMap.at("pac_status").convert(v.pac_status);

            for( uint32_t k = 0; k < 3; ++k )
            {
                vMap.at("position_reference").via.array.ptr[k].convert(v.position_reference[k]);
            }

            for( uint32_t k = 0; k < 3; ++k )
            {
                vMap.at("velocity_reference").via.array.ptr[k].convert(v.velocity_reference[k]);
            }
            return o;
        }
    };

    template<>
    struct pack<busGncNavigation>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            busGncNavigation const &value) const
        {
            packer.pack_map(8u);
            packer << "timestamp" << value.timestamp;
            packer << "position";
            packer.pack_array(3);
            for( uint32_t k = 0; k < 3; ++k )
            {
                packer << value.position[k];
            }
            packer << "velocity";
            packer.pack_array(3);
            for( uint32_t k = 0; k < 3; ++k )
            {
                packer << value.velocity[k];
            }
            packer << "attitude";
            packer.pack_array(4);
            for( uint32_t k = 0; k < 4; ++k )
            {
                packer << value.attitude[k];
            }
            packer << "rates";
            packer.pack_array(3);
            for( uint32_t k = 0; k < 3; ++k )
            {
                packer << value.rates[k];
            }
            packer << "mass" << value.mass;
            packer << "CoM";
            packer.pack_array(3);
            for( uint32_t k = 0; k < 3; ++k )
            {
                packer << value.CoM[k];
            }
            packer << "retargeting_flag" << value.retargeting_flag;
            return packer;
        }
    };

    template<>
    struct convert<busGncNavigation>
    {
        msgpack::object const &operator()(msgpack::object const &o, busGncNavigation &v) const
        {
            if (o.type != msgpack::type::MAP || o.via.map.size != 8u)
            {
                throw msgpack::type_error();
            }
            std::map<std::string, msgpack::object> vMap = o.as<std::map<std::string, msgpack::object>>();
            vMap.at("timestamp").convert(v.timestamp);

            for( uint32_t k = 0; k < 3; ++k )
            {
                vMap.at("position").via.array.ptr[k].convert(v.position[k]);
            }

            for( uint32_t k = 0; k < 3; ++k )
            {
                vMap.at("velocity").via.array.ptr[k].convert(v.velocity[k]);
            }

            for( uint32_t k = 0; k < 4; ++k )
            {
                vMap.at("attitude").via.array.ptr[k].convert(v.attitude[k]);
            }

            for( uint32_t k = 0; k < 3; ++k )
            {
                vMap.at("rates").via.array.ptr[k].convert(v.rates[k]);
            }
            vMap.at("mass").convert(v.mass);

            for( uint32_t k = 0; k < 3; ++k )
            {
                vMap.at("CoM").via.array.ptr[k].convert(v.CoM[k]);
            }
            vMap.at("retargeting_flag").convert(v.retargeting_flag);
            return o;
        }
    };

    template<>
    struct pack<busGncGuidance>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            busGncGuidance const &value) const
        {
            packer.pack_map(5u);
            packer << "timestamp" << value.timestamp;
            packer << "time_to_go" << value.time_to_go;
            packer << "state_error";
            packer.pack_array(13);
            for( uint32_t k = 0; k < 13; ++k )
            {
                packer << value.state_error[k];
            }
            packer << "guidance_reference";
            packer.pack_array(17);
            for( uint32_t k = 0; k < 17; ++k )
            {
                packer << value.guidance_reference[k];
            }
            packer << "current_optimal_trajectory";
            packer.pack_array(540);
            for( uint32_t k = 0; k < 540; ++k )
            {
                packer << value.current_optimal_trajectory[k];
            }
            return packer;
        }
    };

    template<>
    struct convert<busGncGuidance>
    {
        msgpack::object const &operator()(msgpack::object const &o, busGncGuidance &v) const
        {
            if (o.type != msgpack::type::MAP || o.via.map.size != 5u)
            {
                throw msgpack::type_error();
            }
            std::map<std::string, msgpack::object> vMap = o.as<std::map<std::string, msgpack::object>>();
            vMap.at("timestamp").convert(v.timestamp);
            vMap.at("time_to_go").convert(v.time_to_go);

            for( uint32_t k = 0; k < 13; ++k )
            {
                vMap.at("state_error").via.array.ptr[k].convert(v.state_error[k]);
            }

            for( uint32_t k = 0; k < 17; ++k )
            {
                vMap.at("guidance_reference").via.array.ptr[k].convert(v.guidance_reference[k]);
            }

            for( uint32_t k = 0; k < 540; ++k )
            {
                vMap.at("current_optimal_trajectory").via.array.ptr[k].convert(v.current_optimal_trajectory[k]);
            }
            return o;
        }
    };

    template<>
    struct pack<busGncController>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            busGncController const &value) const
        {
            packer.pack_map(3u);
            packer << "timestamp" << value.timestamp;
            packer << "cmd_propulsion";
            packer.pack_array(5);
            for( uint32_t k = 0; k < 5; ++k )
            {
                packer << value.cmd_propulsion[k];
            }
            packer << "engine_on" << value.engine_on;
            return packer;
        }
    };

    template<>
    struct convert<busGncController>
    {
        msgpack::object const &operator()(msgpack::object const &o, busGncController &v) const
        {
            if (o.type != msgpack::type::MAP || o.via.map.size != 3u)
            {
                throw msgpack::type_error();
            }
            std::map<std::string, msgpack::object> vMap = o.as<std::map<std::string, msgpack::object>>();
            vMap.at("timestamp").convert(v.timestamp);

            for( uint32_t k = 0; k < 5; ++k )
            {
                vMap.at("cmd_propulsion").via.array.ptr[k].convert(v.cmd_propulsion[k]);
            }
            vMap.at("engine_on").convert(v.engine_on);
            return o;
        }
    };

    template<>
    struct pack<busGncOtp>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            busGncOtp const &value) const
        {
            packer.pack_map(11u);
            packer << "timestamp" << value.timestamp;
            packer << "optimal_trajectory";
            packer.pack_array(540);
            for( uint32_t k = 0; k < 540; ++k )
            {
                packer << value.optimal_trajectory[k];
            }
            packer << "trajectory_id" << value.trajectory_id;
            packer << "exit_flag" << value.exit_flag;
            packer << "n_iter" << value.n_iter;
            packer << "solve_time" << value.solve_time;
            packer << "min_fuel_formulation_flag" << value.min_fuel_formulation_flag;
            packer << "x_target";
            packer.pack_array(13);
            for( uint32_t k = 0; k < 13; ++k )
            {
                packer << value.x_target[k];
            }
            packer << "x_start";
            packer.pack_array(17);
            for( uint32_t k = 0; k < 17; ++k )
            {
                packer << value.x_start[k];
            }
            packer << "health_status";
            packer.pack_array(16);
            for( uint32_t k = 0; k < 16; ++k )
            {
                packer << value.health_status[k];
            }
            packer << "trajectory_params";
            packer.pack_array(3);
            for( uint32_t k = 0; k < 3; ++k )
            {
                packer << value.trajectory_params[k];
            }
            return packer;
        }
    };

    template<>
    struct convert<busGncOtp>
    {
        msgpack::object const &operator()(msgpack::object const &o, busGncOtp &v) const
        {
            if (o.type != msgpack::type::MAP || o.via.map.size != 11u)
            {
                throw msgpack::type_error();
            }
            std::map<std::string, msgpack::object> vMap = o.as<std::map<std::string, msgpack::object>>();
            vMap.at("timestamp").convert(v.timestamp);

            for( uint32_t k = 0; k < 540; ++k )
            {
                vMap.at("optimal_trajectory").via.array.ptr[k].convert(v.optimal_trajectory[k]);
            }
            vMap.at("trajectory_id").convert(v.trajectory_id);
            vMap.at("exit_flag").convert(v.exit_flag);
            vMap.at("n_iter").convert(v.n_iter);
            vMap.at("solve_time").convert(v.solve_time);
            vMap.at("min_fuel_formulation_flag").convert(v.min_fuel_formulation_flag);

            for( uint32_t k = 0; k < 13; ++k )
            {
                vMap.at("x_target").via.array.ptr[k].convert(v.x_target[k]);
            }

            for( uint32_t k = 0; k < 17; ++k )
            {
                vMap.at("x_start").via.array.ptr[k].convert(v.x_start[k]);
            }

            for( uint32_t k = 0; k < 16; ++k )
            {
                vMap.at("health_status").via.array.ptr[k].convert(v.health_status[k]);
            }

            for( uint32_t k = 0; k < 3; ++k )
            {
                vMap.at("trajectory_params").via.array.ptr[k].convert(v.trajectory_params[k]);
            }
            return o;
        }
    };

    template<>
    struct pack<busGncMvm>
    {
        template<typename Stream>
        msgpack::packer<Stream> &operator()(msgpack::packer<Stream> &packer,
                                            busGncMvm const &value) const
        {
            packer.pack_map(8u);
            packer << "timestamp" << value.timestamp;
            packer << "computation_done" << value.computation_done;
            packer << "recompute_flag" << value.recompute_flag;
            packer << "next_target";
            packer.pack_array(13);
            for( uint32_t k = 0; k < 13; ++k )
            {
                packer << value.next_target[k];
            }
            packer << "next_start";
            packer.pack_array(17);
            for( uint32_t k = 0; k < 17; ++k )
            {
                packer << value.next_start[k];
            }
            packer << "mission_phase_id";
            packer.pack_array(2);
            for( uint32_t k = 0; k < 2; ++k )
            {
                packer << value.mission_phase_id[k];
            }
            packer << "change_trajectory" << value.change_trajectory;
            packer << "mvm_flags";
            packer.pack_array(3);
            for( uint32_t k = 0; k < 3; ++k )
            {
                packer << value.mvm_flags[k];
            }
            return packer;
        }
    };

    template<>
    struct convert<busGncMvm>
    {
        msgpack::object const &operator()(msgpack::object const &o, busGncMvm &v) const
        {
            if (o.type != msgpack::type::MAP || o.via.map.size != 8u)
            {
                throw msgpack::type_error();
            }
            std::map<std::string, msgpack::object> vMap = o.as<std::map<std::string, msgpack::object>>();
            vMap.at("timestamp").convert(v.timestamp);
            vMap.at("computation_done").convert(v.computation_done);
            vMap.at("recompute_flag").convert(v.recompute_flag);

            for( uint32_t k = 0; k < 13; ++k )
            {
                vMap.at("next_target").via.array.ptr[k].convert(v.next_target[k]);
            }

            for( uint32_t k = 0; k < 17; ++k )
            {
                vMap.at("next_start").via.array.ptr[k].convert(v.next_start[k]);
            }

            for( uint32_t k = 0; k < 2; ++k )
            {
                vMap.at("mission_phase_id").via.array.ptr[k].convert(v.mission_phase_id[k]);
            }
            vMap.at("change_trajectory").convert(v.change_trajectory);

            for( uint32_t k = 0; k < 3; ++k )
            {
                vMap.at("mvm_flags").via.array.ptr[k].convert(v.mvm_flags[k]);
            }
            return o;
        }
    };

    }
}
}

#endif // #ifndef _MBOX_LOGGING_INCLUDE_MSGPACK_WRAPPER_OBRTTG_TYPES_HPP_