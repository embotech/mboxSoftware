/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 29 Jun 2021
/// @brief Unit tests for the helper classes and functions in mavlink_tools.hpp.

#ifdef __cplusplus
extern "C"
{
#endif
#include "incaslib.h"
#ifdef __cplusplus
}
#endif
#include "mavlink_tools.hpp"

#include "gtest/gtest.h"

class MockPackage : public obrttg::mavlink::DataPackage
{
public:
    MockPackage() : DataPackage(4, 20000, obrttg::mavlink::SignalMap({
        std::make_tuple(121, "signal1", 0),
        std::make_tuple(122, "signal2", 1),
        std::make_tuple(123, "signal3", 2),
        std::make_tuple(124, "signal4", 3)}))
    {}
};

class DataPackageTestFixture : public ::testing::Test
{
public:
    DataPackageTestFixture() {}

    signal_t getSignal(uint32_t idx)
    {
        return signal_t({
            idx + 121, 
            5632100 + (uint64_t)(10*idx),
            2.23 + double(idx)/10.0
        });
    }

    void addAllSignals()
    {
        m_package.reset();
        for (std::size_t k = 0; k < m_package.size(); k++)
        {
            auto s = getSignal(uint32_t(k));
            ASSERT_EQ(m_package.insert(std::make_unique<const signal_t>(s)), 0);
        }
    }

    void addAllSignalsButOne()
    {
        m_package.reset();
        for (std::size_t k = 0; k < (m_package.size() - 1); k++)
        {
            auto s = std::make_unique<const signal_t>(getSignal(uint32_t(k)));
            ASSERT_EQ(m_package.insert(std::move(s)), 0);
        }
    }
protected:
    MockPackage m_package;
    const uint16_t m_size = 4;
    const uint16_t m_maxAgeDiff = 0.02;
};

TEST_F(DataPackageTestFixture, size)
{
    ASSERT_EQ(m_package.size(), m_size);

    addAllSignalsButOne();
    ASSERT_EQ(m_package.size(), m_size);

    addAllSignals();
    ASSERT_EQ(m_package.size(), m_size);
}

TEST_F(DataPackageTestFixture, empty)
{
    ASSERT_EQ(m_package.empty(), true);

    addAllSignalsButOne();
    ASSERT_EQ(m_package.empty(), false);

    addAllSignals();
    ASSERT_EQ(m_package.empty(), false);
}

TEST_F(DataPackageTestFixture, full)
{
    ASSERT_EQ(m_package.full(), false);

    addAllSignalsButOne();
    ASSERT_EQ(m_package.full(), false);

    addAllSignals();
    ASSERT_EQ(m_package.full(), true);
}

TEST_F(DataPackageTestFixture, exist)
{
    for (uint32_t k = 0; k < m_package.size(); k++)
    {
        ASSERT_EQ(m_package.exist(121+k), true);
    }
    ASSERT_EQ(m_package.exist(121+m_package.size()+1), false);
}

TEST_F(DataPackageTestFixture, contains)
{
    for (uint32_t k = 0; k < m_package.size(); k++)
    {
        auto s = getSignal(k);
        ASSERT_EQ(m_package.contains(s.sig_id), false);
        ASSERT_EQ(m_package.insert(std::make_unique<const signal_t>(s)), 0);
        ASSERT_EQ(m_package.contains(s.sig_id), true);
    }
}

TEST_F(DataPackageTestFixture, insert)
{
    auto s0 = getSignal(0);
    ASSERT_EQ(m_package.insert(std::make_unique<const signal_t>(s0)), 0);

    // Signal was already added
    ASSERT_EQ(m_package.insert(std::make_unique<const signal_t>(s0)), 2);

    auto s1 = getSignal(1);

    // Signal is too new 
    s1.timestamp = s0.timestamp + 2*m_package.maxAgeDiff();
    ASSERT_EQ(m_package.insert(std::make_unique<const signal_t>(s1)), 4);

    // Signal is too old
    s1.timestamp = s0.timestamp - 2*m_package.maxAgeDiff();
    ASSERT_EQ(m_package.insert(std::make_unique<const signal_t>(s1)), 3);

    // Signal does not belong to the package
    s1.sig_id = 2;
    ASSERT_EQ(m_package.insert(std::make_unique<const signal_t>(s1)), 1);
}
