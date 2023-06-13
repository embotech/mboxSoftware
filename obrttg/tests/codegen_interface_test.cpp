/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 28 Jun 2021
/// @brief Type-parameterized unit tests for CodegenInterface derived classes.

#include <string>
#include <filesystem>

#include "gtest/gtest.h"

#include "parameters_interface.hpp"
#include "mvm_interface.hpp"
#include "guidance_interface.hpp"
#include "navigation_interface.hpp"
#include "otp_interface.hpp"

/// Google test references
/// Google typed-parameterized unit test Tutorial: https://github.com/google/googletest/blob/master/docs/advanced.md#type-parameterized-tests
/// Multi type-parameterized unit tests: https://stackoverflow.com/a/52263242
/// Accesing types in a tuple: https://groups.google.com/g/googletestframework/c/HuW15HeRW08
/// using paramType0 =  typename std::tuple_element<0, TypeParam>::type;

// Initialize type-parameterized test fixture
template <typename T>
class CodegenInterfaceFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
       std::filesystem::copy_file("test_params.json", "params.json");
    }
    virtual void TearDown() {
        std::filesystem::remove("params.json");
    }
};

// Declare type-parameteriezed test suite 
TYPED_TEST_SUITE_P(CodegenInterfaceFixture);

// Unit test for initialize method
TYPED_TEST_P(CodegenInterfaceFixture, initialize)
{
    typename std::tuple_element<0, TypeParam>::type codegen{};
    EXPECT_EQ(codegen.initialize(), false);
}

// Unit test for step method
TYPED_TEST_P(CodegenInterfaceFixture, step)
{
    typename std::tuple_element<0, TypeParam>::type codegen{};
    typename std::tuple_element<1, TypeParam>::type input{0};

    ASSERT_EQ(codegen.initialize(), false);
    EXPECT_EQ(codegen.step(input), false);
}

// Register unit tests in the type-parameterized test suite
REGISTER_TYPED_TEST_SUITE_P(CodegenInterfaceFixture, initialize, step);

// Define types to be used in the type-parameterized suite
using CodegenTypes =  ::testing::Types<std::tuple<obrttg::MvmInterface, ExtU_obrttg_mvm_mBox_T>,
                                       std::tuple<obrttg::GuidanceInterface, ExtU_obrttg_guidance_mBox_T>,
                                       std::tuple<obrttg::NavigationInterface, ExtU_obrttg_navigation_mBox_T>,
                                       std::tuple<obrttg::ParametersInterface, void*>,
                                       std::tuple<obrttg::OtpInterface, ExtU_obrttg_otp_sfcn_nlp3_DTVsingle_96d7_T>>;

// Instantiate test suite
INSTANTIATE_TYPED_TEST_SUITE_P(CodegenTests, CodegenInterfaceFixture, CodegenTypes);