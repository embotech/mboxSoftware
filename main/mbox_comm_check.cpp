/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 9 Jun 2021
/// @brief Main program running a communication check between the OBC and the PAC.

#include <iostream>
#include <mavlink_interface.hpp>
#include <time_utils.hpp>

int main()
{

    auto comm = obrttg::MavlinkInterface();
    auto rc = 5;
    int n = 0;
    int maxTries = 50;
    if (rc = comm.initialize())
    {
        std::cout << "Error initializing communication interface (" << rc << ")" << std::endl;
        return 1;
    }
    if (rc = comm.start())
    {
        std::cout << "Error starting communication interface." << std::endl;
        return 1;
    }

    std::cout << std::fixed << std::setprecision(3);
    busGncCommIn rx = {0};
    while (comm.isActive())
    {
        if (auto rc = comm.receive(rx))
        {
            std::cout << "[COMM ERROR " << rc << "]" << std::endl;
        }
        else
        {
            std::cout << "[ " << rx.timestamp_obc << " ] Position: [ " << rx.vehicle_state[0] << ", " << rx.vehicle_state[1] << ", " << rx.vehicle_state[2] << " ] [m]" << std::endl;
            std::cout << "               Velocity: " << rx.vehicle_state[3] << ", " << rx.vehicle_state[4] << ", " << rx.vehicle_state[5] << " ] [m/s]" << std::endl;
            std::cout << "               Mass: " << rx.vehicle_state[13] << " [kg]" << std::endl;
            std::cout << "               Mission status: " << rx.mission_status << std::endl; 
        }

        // Sleep one cycle
        obrttg::msleep(40);
    }

    comm.terminate();

    return 1;

}