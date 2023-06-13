/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

#include "math.h"
#include "float.h"
#include "string.h"
#include "obrttg_input_parser.hpp"

namespace obrttg::input_parser
{

void parse(const busPACinput &in, real_T ts, real_T tnow, busGncCommIn &out)
{
    out.timestamp_obc = ts;
    out.timestamp = tnow;
    out.mission_status = parseMissionStatus(in.missionStatus);
    parseVehicleState(in, out.vehicle_state);
    engineStatus(out.engine_status);
}

double parseMissionStatus(double in)
{
    if ((in >= 1) && (in <= 3)) 
    {
        return in;
    }
    return 1;
}

void parseVehicleState(const busPACinput &in, double state[17])
{
    memcpy(&state[0], in.positionVectorLP, sizeof(in.positionVectorLP));
    memcpy(&state[3], in.velocityVectorLP, sizeof(in.velocityVectorLP));
    double q[4];
    xyzEuler2q(in.eulerAnglesLP, q);
    memcpy(&state[6], q, 4*sizeof(double));
    memcpy(&state[10], in.angularVelocityB, sizeof(in.angularVelocityB));
    state[13] = in.mass;
    memcpy(&state[14], in.cogPositionS, sizeof(in.cogPositionS));
}

void engineStatus(double status[16])
{
    status[0] = 0;
    memcpy(&status[1], obrttg::nominalEngineStatus, sizeof(obrttg::nominalEngineStatus));
}


void xyzEuler2q(const double euler[3], double q[4])
{
    // Get fundamental rotation matrices
    double Croll[9];
    rotMat(euler[0], 0, Croll);
    double Cpitch[9];
    rotMat(euler[1], 1, Cpitch);
    double Cyaw[9];
    rotMat(euler[2], 2, Cyaw);

    // Compute dcm
    double Ctmp[9];
    mult3x3(Cpitch, Cyaw, Ctmp);
    double C[9];
    mult3x3(Croll, Ctmp, C);

    // Compute quaternion
    dcm2q(C, q);
}

void rotMat(double angle, size_t axis, double C[9])
{
    if (axis == 0)
    {
        C[0] = 1.0;
        C[1] = 0.0;
        C[2] = 0.0;;
        C[3] = 0.0;
        C[4] = cos(angle);
        C[5] = sin(angle);
        C[6] = 0.0;
        C[7] = -sin(angle);
        C[8] = cos(angle);
    }
    else if (axis == 1)
    {
        C[0] = cos(angle);
        C[1] = 0.0;
        C[2] = -sin(angle);
        C[3] = 0.0;
        C[4] = 1.0;
        C[5] = 0.0;
        C[6] = sin(angle);
        C[7] = 0.0;
        C[8] = cos(angle);
    }
    else if (axis == 2)
    {
        C[0] = cos(angle);
        C[1] = sin(angle);
        C[2] = 0;
        C[3] = -sin(angle);
        C[4] = cos(angle);
        C[5] = 0;
        C[6] = 0;
        C[7] = 0;
        C[8] = 1.0;
    }
}

void mult3x3(const double a[9], const double b[9], double c[9])
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            c[i + 3*j] = 0;
            for (size_t k = 0; k < 3; k++)
            {
                c[i + 3*j] += a[i + 3*k]*b[k + 3*j];
            }
        }
    }
}

void dcm2q(const double C[9], double q[4])
{
    double den[4] = {
        0.5*sqrt(1 + C[0] + C[1 + 3*1] + C[2 + 3*2]),
        0.5*sqrt(1 + C[0] - C[1 + 3*1] - C[2 + 3*2]),
        0.5*sqrt(1 - C[0] + C[1 + 3*1] - C[2 + 3*2]),
        0.5*sqrt(1 - C[0] - C[1 + 3*1] + C[2 + 3*2])
    };

    size_t maxIdx = 0;
    for (size_t i = 0; i < 4; i++)
    {
        if (den[i] > den[maxIdx])
        {
            maxIdx = i;
        }
    }

    if (maxIdx == 0)
    {
        q[0] = den[0];
        q[1] = (C[2 + 3*1] - C[1 + 3*2])/4.0/den[0];
        q[2] = (C[0 + 3*2] - C[2 + 3*0])/4.0/den[0];
        q[3] = (C[1 + 3*0] - C[0 + 3*1])/4.0/den[0];

    }
    else if (maxIdx == 1)
    {
        q[0] = (C[2 + 3*1] - C[1 + 3*2])/4.0/den[1];
        q[1] = den[1];
        q[2] = (C[0 + 3*1] + C[1 + 3*0])/4.0/den[1];
        q[3] = (C[2 + 3*0] + C[0 + 3*2])/4.0/den[1];

    }
    else if (maxIdx == 2)
    {
        q[0] = (C[0 + 3*2] - C[2 + 3*0])/4.0/den[2];
        q[1] = (C[0 + 3*1] + C[1 + 3*0])/4.0/den[2];
        q[2] = den[2];
        q[3] = (C[1 + 3*2] + C[2 + 3*1])/4.0/den[2];

    }
    else
    {
        q[0] = (C[1 + 3*0] - C[0 + 3*1])/4.0/den[3];
        q[1] = (C[2 + 3*0] + C[0 + 3*2])/4.0/den[3];
        q[2] = (C[2 + 3*1] + C[1 + 3*2])/4.0/den[3];
        q[3] = den[3];
    }

}

} // namespace mbox::input_parser