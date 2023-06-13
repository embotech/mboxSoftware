# Define MATLAB release
set(MATLAB_RELEASE R2020a)

# Define OTP & solver names
set(OTP_NAME nlp3_DTVsingle_96d7)
set(MIN_FUEL_SOLVER_NAME nlp3minFuel_DTVs_6515)
set(MIN_ERROR_SOLVER_NAME nlp3minError_DTVs_d42f)

# Define auto-coded components names
set(GNC_NAVIGATION_REF obrttg_navigation_mBox)
set(GNC_MVM_REF obrttg_mvm_mBox)
set(GNC_GUIDANCE_REF obrttg_guidance_mBox)
set(GNC_OTP_REF obrttg_otp_sfcn_nlp3_DTVsingle_96d7)


# Add OBRTTG subdirectories
add_subdirectory(${MATLAB_RELEASE})
add_subdirectory(commonFiles)
add_subdirectory(otherFiles)
add_subdirectory(${GNC_NAVIGATION_REF})
add_subdirectory(${GNC_MVM_REF})
add_subdirectory(${GNC_GUIDANCE_REF})
add_subdirectory(${GNC_OTP_REF})

# Create interface library
add_library(CodegenObrttg INTERFACE)

target_link_libraries(
    CodegenObrttg
    INTERFACE 
        CodegenObrttgGuidance
        CodegenObrttgMvm
        CodegenObrttgNavigation
        CodegenObrttgOptimalTrajectoryPlanner
)

target_include_directories(
    CodegenObrttg
    INTERFACE 
        commonFiles
        ${MATLAB_RELEASE}/extern/include
        ${MATLAB_RELEASE}/simulink/include
        ${MATLAB_RELEASE}/rtw/c/src
)
