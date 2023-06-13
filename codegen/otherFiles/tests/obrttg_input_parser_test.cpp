/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

#include "gtest/gtest.h"
#include "string.h"
#include "obrttg_input_parser.hpp"

class ObrttgInputParserTestFixture : public ::testing::Test
{
public:
    ObrttgInputParserTestFixture(){}
};

TEST_F(ObrttgInputParserTestFixture, mult3x3)
{
    double a[9] = {0.0975,    0.2785,    0.5469,    0.9575,    0.9649,    0.1576,    0.9706,    0.9572,    0.4854};
    double b[9] = {0.8003,    0.1419,    0.4218,    0.9157,    0.7922,    0.9595,    0.6557,    0.0357,    0.8491};
    double c[9];
    double cExp[9] = {0.62329758,    0.76354982,    0.66478923,    1.77910295,    1.93784963,    1.09138835,    0.92224996,    1.0298179,    0.77638179};

    obrttg::input_parser::mult3x3(a, b, c);
    for (size_t i = 0; i < 9; i++)
    {
        EXPECT_NEAR(c[i], cExp[i], 1e-12) << "Actual and expected result differ at index " << i;
    }
}

TEST_F(ObrttgInputParserTestFixture, dcm2q)
{
    double C[9] = {0.542582484401531,  -0.839047615458186,   0.040041810830607,   0.804411613572383,   0.505273941429831,  -0.312442314774805,   0.241921895599668,   0.201735825043288, 0.949092436659131};
    double q[4];
    double qExp[4] = {0.865584897986687,  -0.148505981624116,   0.058307418844363,  -0.474667254723709};

    obrttg::input_parser::dcm2q(C, q);
    for (size_t i = 0; i < 4; i++)
    {
        EXPECT_NEAR(q[i], qExp[i], 1e-12) << "Actual and expected result differ at index " << i;
    }
}

TEST_F(ObrttgInputParserTestFixture, xyzEuler2q)
{
    double euler[3] = { -0.209439510239320, 0.244346095279206, -0.977384381116825 };
    double q[4];
    double qExp[4] = {0.865584897986687,  -0.148505981624116,   0.058307418844363,  -0.474667254723709};

    obrttg::input_parser::xyzEuler2q(euler, q);
    for (size_t i = 0; i < 4; i++)
    {
        EXPECT_NEAR(q[i], qExp[i], 1e-12) << "Actual and expected result differ at index " << i;
    }
}

TEST_F(ObrttgInputParserTestFixture, parseVehicleState)
{
    busPACinput input;
    double stateExp[17];
    double state[17];
    double pos[3] = {1.0, 2.0, 3.0};
    memcpy(input.positionVectorLP, pos, 3*sizeof(double));
    memcpy(&stateExp[0], pos, 3*sizeof(double));
    double vel[3] = {4.0, 5.0, 6.0};
    memcpy(input.velocityVectorLP, vel, 3*sizeof(double));
    memcpy(&stateExp[3], vel, 3*sizeof(double));
    double euler[3] = { -0.209439510239320, 0.244346095279206, -0.977384381116825 };
    double q[4] = {0.865584897986687,  -0.148505981624116,   0.058307418844363,  -0.474667254723709};
    memcpy(input.eulerAnglesLP, euler, 3*sizeof(double));
    memcpy(&stateExp[6], q, 4*sizeof(double));
    double omega[3] = {7.0, 8.0, 9.0};
    memcpy(input.angularVelocityB, omega, 3*sizeof(double));
    memcpy(&stateExp[10], omega, 3*sizeof(double));
    double mass = 10.0;
    input.mass = mass;
    stateExp[13] = mass;
    double cog[3] = {11.0, 12.0, 13.0};
    memcpy(input.cogPositionS, cog, 3*sizeof(double));
    memcpy(&stateExp[14], cog, 3*sizeof(double));

    obrttg::input_parser::parseVehicleState(input, state);
    for (size_t i = 0; i < 17; i++)
    {
        EXPECT_NEAR(state[i], stateExp[i], 1e-12) << "Actual and expected result differ at index " << i;
    }
}