/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 09 Mar 2022
/// @brief Implementation of DynBitSet, DataPackace and derived helper classes to support the Mavlink communication interface.

#ifdef __cplusplus
extern "C"
{
#endif
#include "incaslib.h"
#ifdef __cplusplus
}
#endif

#include "mavlink_tools.hpp"

namespace obrttg::mavlink
{
    DataPackage::DataPackage(size_t size, const double &maxAge, const SignalMap &map)
    :   m_size(size),
        m_maxAgeDiff(maxAge),
        m_map(map)
    {
        reset();
    }

    void DataPackage::reset()
    {
        m_bset.clear();
        m_bset.resize(m_size);
        m_bset.reset();
        m_timestamp = 0;
        m_signals.clear();
        m_signals.resize(m_size);
    }
    
    int DataPackage::check(const std::unique_ptr<const signal_t> &s) const
    {
        if (!exist(s->sig_id))
        {
            return 1;
        }
        if (contains(s->sig_id))
        {
            if (m_timestamp == s->timestamp)
            {
                // Exactly same signal
                return 2;
            }
        }
        if (!empty())
        {
            if ((m_timestamp > s->timestamp) && ((m_timestamp - s->timestamp) > m_maxAgeDiff))
            {
                return 3;
            }
            if ((s->timestamp > m_timestamp) && ((s->timestamp - m_timestamp) > m_maxAgeDiff))
            {
                return 4;
            }
        }
        return 0;
    }

    int DataPackage::insert(std::unique_ptr<const signal_t> signal)
    {
        
        if (int rc = check(signal))
        {
            return rc;
        }

        // Update bitset
        m_bset.set(m_map.at(signal->sig_id), 1);

        // Update the timestamp
        if (!m_timestamp)
        {
            m_timestamp = signal->timestamp;
        }
        else
        {
            m_timestamp = (m_timestamp > signal->timestamp) ? signal->timestamp : m_timestamp;
        }

        // Add signal to the list
        m_signals[m_map.at(signal->sig_id)] = std::move(signal);

        return 0; 
    }


    RxPackage::RxPackage() : DataPackage (
        RX_N_SIGNALS,
        MAX_AGE_DIFF,
        SignalMap(
        {
            std::make_tuple(RTE_GNC_X_POSITION_LAUNCHPAD, "pos_x", 0),
            std::make_tuple(RTE_GNC_Y_POSITION_LAUNCHPAD, "pos_y", 1),
            std::make_tuple(RTE_GNC_Z_POSITION_LAUNCHPAD, "pos_z", 2),
            std::make_tuple(RTE_GNC_X_VELOCITY_LAUNCHPAD, "vel_x", 3),
            std::make_tuple(RTE_GNC_Y_VELOCITY_LAUNCHPAD, "vel_y", 4),
            std::make_tuple(RTE_GNC_Z_VELOCITY_LAUNCHPAD, "vel_z", 5),
            std::make_tuple(RTE_GNC_ROLL_ANGLE_BODY, "roll", 6),
            std::make_tuple(RTE_GNC_PITCH_ANGLE_BODY, "pitch", 7),
            std::make_tuple(RTE_GNC_YAW_ANGLE_BODY, "yaw", 8),
            std::make_tuple(RTE_GNC_OMEGA_X_BODY, "omega_x", 9),
            std::make_tuple(RTE_GNC_OMEGA_Y_BODY, "omega_y", 10),
            std::make_tuple(RTE_GNC_OMEGA_Z_BODY, "omega_z", 11),
            std::make_tuple(RTE_GNC_CoM_X_M, "cog_x", 12),
            std::make_tuple(RTE_GNC_CoM_Y_M, "cog_y", 13),
            std::make_tuple(RTE_GNC_CoM_Z_M, "cog_z", 14),
            std::make_tuple(RTE_GNC_MASS, "mass", 15),
            std::make_tuple(RTE_GNC_MISSION_STATUS, "mission_status", 16)
        })) {} 

    DTVState::DTVState(const RxPackage &rxPkg)
    {
        timestamp = (double)(rxPkg.timestamp())/1000.0;
        data.positionVectorLP[0] = rxPkg["pos_x"].signal_value;
        data.positionVectorLP[1] = rxPkg["pos_y"].signal_value;
        data.positionVectorLP[2] = rxPkg["pos_z"].signal_value; 
        data.velocityVectorLP[0] = rxPkg["vel_x"].signal_value;
        data.velocityVectorLP[1] = rxPkg["vel_y"].signal_value;
        data.velocityVectorLP[2] = rxPkg["vel_z"].signal_value;
        data.eulerAnglesLP[0] = rxPkg["roll"].signal_value;
        data.eulerAnglesLP[1] = rxPkg["pitch"].signal_value;
        data.eulerAnglesLP[2] = rxPkg["yaw"].signal_value;
        data.angularVelocityB[0] = rxPkg["omega_x"].signal_value;
        data.angularVelocityB[1] = rxPkg["omega_y"].signal_value;
        data.angularVelocityB[2] = rxPkg["omega_z"].signal_value;
        data.cogPositionS[0] = rxPkg["cog_x"].signal_value;
        data.cogPositionS[1] = rxPkg["cog_y"].signal_value;
        data.cogPositionS[2] = rxPkg["cog_z"].signal_value;
        data.mass = rxPkg["mass"].signal_value;
        data.missionStatus = rxPkg["mission_status"].signal_value;
    }

    DTVState::operator RxPackage() const
    {
        RxPackage rxPkg;
        auto ts = (uint64_t)(timestamp*1000.0);
        auto a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_X_POSITION_LAUNCHPAD,
                    .timestamp = ts,
                    .signal_value = data.positionVectorLP[0]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_Y_POSITION_LAUNCHPAD,
                    .timestamp = ts,
                    .signal_value = data.positionVectorLP[1]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_Z_POSITION_LAUNCHPAD,
                    .timestamp = ts,
                    .signal_value = data.positionVectorLP[2]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_X_VELOCITY_LAUNCHPAD,
                    .timestamp = ts,
                    .signal_value = data.velocityVectorLP[0]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_Y_VELOCITY_LAUNCHPAD,
                    .timestamp = ts,
                    .signal_value = data.velocityVectorLP[1]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_Z_VELOCITY_LAUNCHPAD,
                    .timestamp = ts,
                    .signal_value = data.velocityVectorLP[2]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_ROLL_ANGLE_BODY,
                    .timestamp = ts,
                    .signal_value = data.eulerAnglesLP[0]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_PITCH_ANGLE_BODY,
                    .timestamp = ts,
                    .signal_value = data.eulerAnglesLP[1]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_YAW_ANGLE_BODY,
                    .timestamp = ts,
                    .signal_value = data.eulerAnglesLP[2]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_OMEGA_X_BODY,
                    .timestamp = ts,
                    .signal_value = data.angularVelocityB[0]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_OMEGA_Y_BODY,
                    .timestamp = ts,
                    .signal_value = data.angularVelocityB[1]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_OMEGA_Z_BODY,
                    .timestamp = ts,
                    .signal_value = data.angularVelocityB[2]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_CoM_X_M,
                    .timestamp = ts,
                    .signal_value = data.cogPositionS[0]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_CoM_Y_M,
                    .timestamp = ts,
                    .signal_value = data.cogPositionS[1]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_CoM_Z_M,
                    .timestamp = ts,
                    .signal_value = data.cogPositionS[2]}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_MASS,
                    .timestamp = ts,
                    .signal_value = data.mass}));
        a0 = rxPkg.insert(std::make_unique<const signal_t>(signal_t{
                    .sig_id = RTE_GNC_MISSION_STATUS,
                    .timestamp = ts,
                    .signal_value = data.missionStatus}));
        return rxPkg;
    }

    DTVState::operator busGncCommIn() const
    {
        busGncCommIn out;
        double tnow = ((double)(mnow()))/1000.0;
        obrttg::input_parser::parse(data, timestamp, tnow, out);
        return out;
    }

    TxPackage::TxPackage() : DataPackage(
        TX_N_SIGNALS,
        MAX_AGE_DIFF,
        SignalMap(
        {
            //std::make_tuple(RTE_EMBOTECH_PAC_EMBOTECH_PAC_TIMESTAMP_SIGNAL, "timestamp", 0),
            std::make_tuple(RTE_EMBOTECH_PAC_STATUS_SIGNAL, "pac_status", 0),
            std::make_tuple(RTE_EMBOTECH_PAC_REFERENCE_POSITION_UP_M_SIGNAL, "pos_x", 1),
            std::make_tuple(RTE_EMBOTECH_PAC_REFERENCE_POSITION_EAST_M_SIGNAL, "pos_y", 2),
            std::make_tuple(RTE_EMBOTECH_PAC_REFERENCE_POSITION_NORTH_M_SIGNAL, "pos_z", 3),
            std::make_tuple(RTE_EMBOTECH_PAC_REFERENCE_VELOCITY_X_MS_SIGNAL, "vel_x", 4),
            std::make_tuple(RTE_EMBOTECH_PAC_REFERENCE_VELOCITY_Y_MS_SIGNAL, "vel_y", 5),
            std::make_tuple(RTE_EMBOTECH_PAC_REFERENCE_VELOCITY_Z_MS_SIGNAL, "vel_z", 6),
            std::make_tuple(RTE_EMBOTECH_PAC_REFERENCE_TIMESTAMP, "timestamp", 7)
        })) {}
    
    DTVReference::DTVReference(const TxPackage &txPkg)
    {
        timestamp = txPkg["timestamp"].signal_value/1000.0;
        pacStatus = (int)(txPkg["pac_status"].signal_value);
        position[0] = txPkg["pos_x"].signal_value;
        position[1] = txPkg["pos_y"].signal_value;
        position[2] = txPkg["pos_z"].signal_value;
        velocity[0] = txPkg["vel_x"].signal_value;
        velocity[1] = txPkg["vel_y"].signal_value;
        velocity[2] = txPkg["vel_z"].signal_value;
    }

    DTVReference::operator TxPackage() const
    {
        TxPackage txPkg;
        namespace clk = std::chrono;
        uint64_t ts = clk::duration_cast<clk::milliseconds>(clk::system_clock::now().time_since_epoch()).count();
        //uint64_t ts = (uint64_t)(timestamp);

        // PAC status 
        txPkg.insert(std::make_unique<const signal_t>(signal_t{
            .sig_id = RTE_EMBOTECH_PAC_STATUS_SIGNAL,
            .timestamp = ts,
            .signal_value = (double)(pacStatus)}));
        // Position x
        txPkg.insert(std::make_unique<const signal_t>(signal_t{
            .sig_id = RTE_EMBOTECH_PAC_REFERENCE_POSITION_UP_M_SIGNAL,
            .timestamp = ts,
            .signal_value = position[0]}));
        // Position y
        txPkg.insert(std::make_unique<const signal_t>(signal_t{
            .sig_id = RTE_EMBOTECH_PAC_REFERENCE_POSITION_EAST_M_SIGNAL,
            .timestamp = ts,
            .signal_value = position[1]}));
        // Position z
        txPkg.insert(std::make_unique<const signal_t>(signal_t{
            .sig_id = RTE_EMBOTECH_PAC_REFERENCE_POSITION_NORTH_M_SIGNAL,
            .timestamp = ts,
            .signal_value = position[2]}));
        // Velocity x
        txPkg.insert(std::make_unique<const signal_t>(signal_t{
            .sig_id = RTE_EMBOTECH_PAC_REFERENCE_VELOCITY_X_MS_SIGNAL,
            .timestamp = ts,
            .signal_value = velocity[0]}));
        // Velocity y
        txPkg.insert(std::make_unique<const signal_t>(signal_t{
            .sig_id = RTE_EMBOTECH_PAC_REFERENCE_VELOCITY_Y_MS_SIGNAL,
            .timestamp = ts,
            .signal_value = velocity[1]}));
        // Velocity z
        txPkg.insert(std::make_unique<const signal_t>(signal_t{
            .sig_id = RTE_EMBOTECH_PAC_REFERENCE_VELOCITY_Z_MS_SIGNAL,
            .timestamp = ts,
            .signal_value = velocity[2]}));
        // Reference timestamp
        txPkg.insert(std::make_unique<const signal_t>(signal_t{
            .sig_id = RTE_EMBOTECH_PAC_REFERENCE_TIMESTAMP,
            .timestamp = ts,
            .signal_value = timestamp*1000.0}));
        
        return txPkg;
    }
}