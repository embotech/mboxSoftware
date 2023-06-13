/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

#ifndef _MBOX_PARAMETERS_HPP_
#define _MBOX_PARAMETERS_HPP_

#include "json.hpp" // nlhomann json, used to read the json file
#include <string>   // std::string type used to pass the file path

#ifndef BOOLEAN_T
#define BOOLEAN_T unsigned char
#endif // #ifndef BOOLEAN_T
typedef BOOLEAN_T boolean_T;

#ifndef REAL_T
#define REAL_T double
#endif // #ifndef REAL_T
typedef REAL_T real_T;

#ifndef MBOX_PARAMS_N_WAYPOINTS
#define MBOX_PARAMS_N_WAYPOINTS 3
#endif // #ifndef MBOX_PARAMS_N_WAYPOINTS

#ifndef MBOX_PARAMS_DIM_WAYPOINTS
#define MBOX_PARAMS_DIM_WAYPOINTS 6
#endif // #ifndef MBOX_PARAMS_DIM_WAYPOINTS


/***** STRUCT DEFINITIONS *****/
#ifndef DEFINED_TYPEDEF_FOR_busValidationOptions_
#define DEFINED_TYPEDEF_FOR_busValidationOptions_

// bus validation options bus
typedef struct {
    real_T retargetingEventTime;
} busValidationOptions;

#endif // #ifndef DEFINED_TYPEDEF_FOR_busValidationOptions_


#ifndef DEFINED_TYPEDEF_FOR_busMboxParameters_
#define DEFINED_TYPEDEF_FOR_busMboxParameters_

// mbox parameters bus
typedef struct {
    real_T trackingErrorThreshold;
    real_T waypoints[MBOX_PARAMS_N_WAYPOINTS*MBOX_PARAMS_DIM_WAYPOINTS];
    real_T takeOffHeight;
    real_T verticalTakeOffVelocity[3];
    boolean_T offlineOtpGeneration;
    real_T launchPadPosition[3];
    real_T maxSpeedConstraint;
    real_T tiltAngleConstraint;
    real_T glideSlopeAngleConstraint;
} busMboxParameters;

#endif // #ifndef DEFINED_TYPEDEF_FOR_busMboxParameters_

#ifndef DEFINED_TYPEDEF_FOR_busGncParameters_
#define DEFINED_TYPEDEF_FOR_busGncParameters_

// gnc parameters bus containing the mbox and the bus validation buses
typedef struct {
    busMboxParameters gncParameters;
    busValidationOptions validOptionParameters;
} busGncParameters;

#endif // #ifndef DEFINED_TYPEDEF_FOR_busGncParameters_

namespace obrttg::parameters
{
class Loader
{
public:
    // Enumeration defining the different error modes
    typedef enum Status {
        NOT_INITIALIZED = 0,
        SUCCESS,
        FILE_NOT_FOUND,
        PARSER_ERROR,
        FORMAT_ERROR
    } Status;

    // Struct containing the loader configuration
    typedef struct Config {
        std::string m_file; // Parameter file full path
        struct Wps {
            int n;          // Number of waypoints
            int dim;        // Dimension of each waypoint
            Wps(int n, int dim) : n(n), dim(dim) {}
        } m_wps;
        Config() : m_file(""), m_wps(0,0) {}
        Config(std::string file, int n, int dim) : m_file(file), m_wps(n, dim) {}
    } Config;

    // @brief Creates Loader object with no configuration. No parameter file will be loaded.
    Loader();

    // @brief Creates Loader object with the provided configuration and loads the defined parameter file.
    //
    // @param[in] cfg Loader configuration object
    Loader(const Config &cfg);

    // @brief Loads the file defined in the provided configuration
    //
    // @param[in] cfg Loader configuration object
    void init(const Config &cfg);

    // @brief Getter function returning the loaded mission parameter bus
    //
    // @return Loaded mission parameter bus
    busGncParameters get();

    // @brief Checks if the loader is ready, i.e. the parameters file was correctly loaded.
    //
    // @return true if the parameter file was loaded, false otherwise
    bool ready();

    // @brief Checks the current loader status
    //
    // @return the current loader status
    Status status();
    
private:

    // @brief Loads the parameters file defined in the Loader configuration.
    void load();

    // @brief Checks if the loaded json file has the correct format, i.e. contains the required fields.
    //
    // @return true if json file is correct, false otherwise
    bool check(const nlohmann::json &j);

  Config m_cfg;
  Status m_status;
  busGncParameters m_params;
};

} // namespace obrttg::parameters

#endif // #ifndef _MBOX_PARAMETERS_HPP_