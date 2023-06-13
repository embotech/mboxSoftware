/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

#include "json.hpp" // nlhomann json, used to read the json file
#include <fstream>  // used to read the json file
#include "string.h" // to use memcpy
#include <filesystem>

#include "obrttg_parameters_loader.hpp"

namespace obrttg::parameters
{
Loader::Loader()
{
    m_status = Loader::Status::NOT_INITIALIZED;
}

Loader::Loader(const Loader::Config &cfg)
     : m_cfg(cfg), m_status(Loader::Status::NOT_INITIALIZED)
{
    load();
}
void Loader::init(const Loader::Config &cfg)
{
   m_cfg = cfg;
   load();
}

busGncParameters Loader::get()
{
    return m_params;
}

bool Loader::ready()
{
    return (m_status == Loader::SUCCESS);
}

Loader::Status Loader::status()
{
    return m_status;
}

void Loader::load()
{
    // Check if file exists
    if (!std::filesystem::exists(m_cfg.m_file) || !std::filesystem::is_regular_file(m_cfg.m_file))
    {
        m_status = Loader::Status::FILE_NOT_FOUND;
        return;
    }
    
    // Parse json file
    std::ifstream file(m_cfg.m_file);
    nlohmann::json j = nlohmann::json::parse(file);

    if (j.is_discarded())
    {
       m_status = Loader::Status::PARSER_ERROR;
       return;
    }

    // Check file
    if (!check(j))
    {
        m_status = Loader::Status::FORMAT_ERROR;
        return;
    }

    /** Extract scalars **/
    m_params.validOptionParameters.retargetingEventTime = j["retargetingEventTime"].get<double>();
    m_params.gncParameters.trackingErrorThreshold = j["trackingErrorThreshold"].get<double>();
    m_params.gncParameters.takeOffHeight = j["takeOffHeight"].get<double>();
    m_params.gncParameters.offlineOtpGeneration = j["offlineOtpGeneration"].get<bool>();
    m_params.gncParameters.maxSpeedConstraint = j["maxSpeedConstraint"].get<double>();
    m_params.gncParameters.tiltAngleConstraint = j["tiltAngleConstraint"].get<double>();
    m_params.gncParameters.glideSlopeAngleConstraint = j["glideSlopeAngleConstraint"].get<double>();

    /** Extract vectors **/
    memcpy(m_params.gncParameters.verticalTakeOffVelocity,
           &j["verticalTakeOffVelocity"].get<std::vector<double>>()[0], 
           sizeof(busMboxParameters::verticalTakeOffVelocity));
    memcpy(m_params.gncParameters.launchPadPosition,
           &j["launchPadPosition"].get<std::vector<double>>()[0],
           sizeof(busMboxParameters::launchPadPosition));

    /** Extract waypoints **/
    // outer loop though the waypoints
    for (int i=0; i<m_cfg.m_wps.n; ++i)
    {
        // get a waypoint
        memcpy(&m_params.gncParameters.waypoints[i*m_cfg.m_wps.dim],
               &j["waypoints"][i].get<std::vector<double>>()[0],
               m_cfg.m_wps.dim*sizeof(double));
    }

    m_status = Loader::Status::SUCCESS;
}

bool Loader::check(const nlohmann::json &j)
{
    if (!j.contains("retargetingEventTime") ||
        !j.contains("trackingErrorThreshold") ||
        !j.contains("takeOffHeight") ||
        !j.contains("offlineOtpGeneration") ||
        !j.contains("maxSpeedConstraint") ||
        !j.contains("tiltAngleConstraint") ||
        !j.contains("glideSlopeAngleConstraint") ||
        !j.contains("verticalTakeOffVelocity") ||
        !j.contains("launchPadPosition") ||
        !j.contains("waypoints"))
    {
        return false;
    }
    return true;

}

//bool load(const std::string &fullFilePath, busGncParameters &gncParams, const ParamsCfg &cfg)
//{
//    /** get json file **/
//    std::ifstream file(fullFilePath);
//    nlohmann::json j = nlohmann::json::parse(file);
//
//    if (j.is_discarded())
//    {
//           return false;
//    }
//
//    /** Extract scalars **/
//    gncParams.validOptionParameters.retargetingEventTime = j["retargetingEventTime"].get<double>();
//    gncParams.gncParameters.trackingErrorThreshold = j["trackingErrorThreshold"].get<double>();
//    gncParams.gncParameters.takeOffHeight = j["takeOffHeight"].get<double>();
//    gncParams.gncParameters.offlineOtpGeneration = j["offlineOtpGeneration"].get<bool>();
//    gncParams.gncParameters.maxSpeedConstraint = j["maxSpeedConstraint"].get<double>();
//    gncParams.gncParameters.tiltAngleConstraint = j["tiltAngleConstraint"].get<double>();
//    gncParams.gncParameters.glideSlopeAngleConstraint = j["glideSlopeAngleConstraint"].get<double>();
//
//    /** Extract vectors **/
//    memcpy(gncParams.gncParameters.verticalTakeOffVelocity,
//           &j["verticalTakeOffVelocity"].get<std::vector<double>>()[0], 
//           sizeof(busMboxParameters::verticalTakeOffVelocity));
//    memcpy(gncParams.gncParameters.launchPadPosition,
//           &j["launchPadPosition"].get<std::vector<double>>()[0],
//           sizeof(busMboxParameters::launchPadPosition));
//
//    /** Extract waypoints **/
//    // outer loop though the waypoints
//    for (int i=0; i<cfg.wps.n; ++i)
//    {
//        // get a waypoint
//        memcpy(&gncParams.gncParameters.waypoints[i*cfg.wps.dim],
//               &j["waypoints"][i].get<std::vector<double>>()[0],
//               cfg.wps.dim*sizeof(double));
//    }
//
//    return true;   
//}

} // namespace obrttg::parameters