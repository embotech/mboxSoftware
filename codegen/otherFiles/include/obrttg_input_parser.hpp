/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

#ifndef _MBOX_INPUT_PARSER_HPP_
#define _MBOX_INPUT_PARSER_HPP_

#ifndef BOOLEAN_T
#define BOOLEAN_T unsigned char
#endif // #ifndef BOOLEAN_T
typedef BOOLEAN_T boolean_T;

#ifndef REAL_T
#define REAL_T double
#endif // #ifndef REAL_T
typedef REAL_T real_T;

#ifndef DEFINED_TYPEDEF_FOR_busPACinput_
#define DEFINED_TYPEDEF_FOR_busPACinput_ 
typedef struct {
  real_T sifGuidSelection;
  boolean_T sifStateOK;
  real_T missionStatus;
  real_T positionVectorLP[3];
  real_T velocityVectorLP[3];
  real_T eulerAnglesLP[3];
  real_T angularVelocityB[3];
  real_T eulerAnglesRatesLP[3];
  real_T cogPositionS[3];
  real_T mass;
} busPACinput;
#endif

#ifndef DEFINED_TYPEDEF_FOR_busGncCommIn_
#define DEFINED_TYPEDEF_FOR_busGncCommIn_ 
typedef struct {
  real_T timestamp_obc;
  real_T timestamp;
  real_T mission_status;
  real_T vehicle_state[17];
  real_T engine_status[16];
} busGncCommIn;
#endif

namespace obrttg
{
#ifndef CONST_REAL_T_NOMINAL_ENGINE_STATUS
#define CONST_REAL_T_NOMINAL_ENGINE_STATUS
static const real_T nominalEngineStatus[15] = {0.0, 112.0, 800.0, -0.1745329251994, 0.1745329251994, 
                                               1.0, 112.0, 800.0, -0.1745329251994, 0.1745329251994,
                                               0.0, 112.0, 800.0, -0.1745329251994, 0.1745329251994};
#endif // #ifndef CONST_REAL_T_NOMINAL_ENGINE_STATUS
} // namespace obrttg

namespace obrttg::input_parser
{
    /* This function parses the OBC busPACinput output into the busGncCommIn input for the PAC.
     * The main functionality consists on converting the XYZ Euler angles defining the vehicle attitude into a
     * attitude quaternion.
     *
     * INPUTS
     *  - in: busPACinput structure containing the OBC output.
     *  - ts: Timestamp of the OBC output.
     *  - tnow: Time at which the OBC output package is received.
     *  - out: busGncCommIn structure containing the input for the PAC software.
     */
    void parse(const busPACinput &in, real_T ts, real_T tnow, busGncCommIn &out);
    
    /* Parses the OBC mission status flag
     *
     * INPUTS
     *  - in: OBC mission status flag:
     *      - 1: ground
     *      - 2: baseline
     *      - 3: experimental
     */
    double parseMissionStatus(double in);

    void parseVehicleState(const busPACinput &in, double state[17]);
    
    void engineStatus(double status[16]);

    void xyzEuler2q(const double euler[3], double q[4]);

    void rotMat(const double angle, size_t axis, double C[9]);

    void mult3x3(const double a[9], const double b[9], double c[9]);

    void dcm2q(const double C[9], double q[4]);

} // namespace obrttg::input_parser

#endif // #ifndef _MBOX_INPUT_PARSER_HPP_