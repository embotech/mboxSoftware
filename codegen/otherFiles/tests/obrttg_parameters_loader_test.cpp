/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

#include "gtest/gtest.h"
#include "string.h"
#include "obrttg_parameters_loader.hpp"

class ObrttgParametersLoaderTestFixture : public ::testing::Test
{
public:
    ObrttgParametersLoaderTestFixture(){}
    obrttg::parameters::Loader loader;
};

TEST_F(ObrttgParametersLoaderTestFixture, success)
{
    std::string file = "test_params.json"; // File that exists and is correct
    loader.init(obrttg::parameters::Loader::Config(file, MBOX_PARAMS_N_WAYPOINTS, MBOX_PARAMS_DIM_WAYPOINTS));
    ASSERT_EQ(loader.ready(), true);
}

TEST_F(ObrttgParametersLoaderTestFixture, not_initialized)
{
    ASSERT_EQ(loader.ready(), false);
    ASSERT_EQ(loader.status(), loader.NOT_INITIALIZED);
}

TEST_F(ObrttgParametersLoaderTestFixture, file_not_found)
{
    std::string file = "other_params.json"; // File that does not exist
    loader.init(obrttg::parameters::Loader::Config(file, MBOX_PARAMS_N_WAYPOINTS, MBOX_PARAMS_DIM_WAYPOINTS));
    ASSERT_EQ(loader.ready(), false);
    ASSERT_EQ(loader.status(), loader.FILE_NOT_FOUND);
}

TEST_F(ObrttgParametersLoaderTestFixture, format_error)
{
    std::string file = "test_params_error.json"; // File that exists but is wrong
    loader.init(obrttg::parameters::Loader::Config(file, MBOX_PARAMS_N_WAYPOINTS, MBOX_PARAMS_DIM_WAYPOINTS));
    ASSERT_EQ(loader.ready(), false);
    ASSERT_EQ(loader.status(), loader.FORMAT_ERROR);
}
