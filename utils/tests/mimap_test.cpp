/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 29 Jun 2021
/// @brief Unit tests for mimap template class.

#include <string>
#include <tuple>

#include "mimap.hpp"
#include "gtest/gtest.h"

class MimapTestFixture : public ::testing::Test
{
public:
    MimapTestFixture()
        : m_key1({0, 1, 2, 3, 4, 5, 9}),
          m_key2({"zero", "one", "two", "three", "four", "five", "nine"}),
          m_values({10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 19.0})
    {
        initialize();
    }

    void initialize()
    {
        m_map.clear();
        for (size_t k = 0; k < m_key1.size(); k++)
        {
            m_map.insert(std::tuple<int, std::string, double>(m_key1[k], m_key2[k], m_values[k]));
        }
    }

protected:
    const std::vector<int> m_key1;
    std::vector<std::string> m_key2;
    std::vector<double> m_values;
    embo::mimap<int, std::string, double> m_map;
};

TEST_F(MimapTestFixture, size)
{
    ASSERT_EQ(m_map.size(), m_key1.size());
}

TEST_F(MimapTestFixture, insert)
{
    auto size0 = m_map.size(); 
    auto entry = std::tuple<int, std::string, double>(6, "six", 16.0);

    // Insert new entry
    ASSERT_EQ(m_map.insert(entry), true);
    EXPECT_EQ(m_map.size(), size0+1);

    // Insert repeated entry (expect failure)
    ASSERT_EQ(m_map.insert(entry), false);
    ASSERT_EQ(m_map.size(), size0+1);

    // Insert similar entry with the same second key (expect failure)
    entry = std::tuple<int, std::string, double>(7, "six", 17.0);
    ASSERT_EQ(m_map.insert(entry), false);
    ASSERT_EQ(m_map.size(), size0+1);

    // Insert similar entry with the same first key (expect failure)
    entry = std::tuple<int, std::string, double>(6, "seven", 17.0);
    ASSERT_EQ(m_map.insert(entry), false);
    ASSERT_EQ(m_map.size(), size0+1);
}

TEST_F(MimapTestFixture, access_operator)
{

    for (size_t k = 0; k < m_key1.size(); k++)
    {
        ASSERT_EQ(m_map[m_key1[k]], m_values[k]);
    }
    for (size_t k = 0; k < m_key2.size(); k++)
    {
        ASSERT_EQ(m_map[m_key2[k]], m_values[k]);
    }
}

TEST_F(MimapTestFixture, access_at)
{

    for (size_t k = 0; k < m_key1.size(); k++)
    {
        ASSERT_EQ(m_map.at(m_key1[k]), m_values[k]);
    }
    for (size_t k = 0; k < m_key2.size(); k++)
    {
        ASSERT_EQ(m_map.at(m_key2[k]), m_values[k]);
    }
    
    // Check that at access method throws exception when accessing an out-of-bounds element
    EXPECT_THROW(m_map.at(m_values.size()), std::out_of_range);
}


TEST_F(MimapTestFixture, find)
{
    for (size_t k = 0; k < m_key1.size(); k++)
    {
        auto it = m_map.find(m_key1[k]);
        ASSERT_TRUE(it != m_map.end());
        EXPECT_EQ(it->first_key, m_key1[k]);
        EXPECT_STREQ(it->second_key.c_str(), m_key2[k].c_str());
        EXPECT_EQ(it->value, m_values[k]);
    }
    for (size_t k = 0; k < m_key2.size(); k++)
    {
        auto it = m_map.find(m_key2[k]);
        ASSERT_TRUE(it != m_map.end());
        EXPECT_EQ(it->first_key, m_key1[k]);
        EXPECT_STREQ(it->second_key.c_str(), m_key2[k].c_str());
        EXPECT_EQ(it->value, m_values[k]);
    }

}

TEST_F(MimapTestFixture, erase)
{
    // Test removing one element at a time from the map
    std::vector<size_t> idx2test(m_key1.size());
    std::generate(idx2test.begin(), idx2test.end(), [n = 0] () mutable { return n++; });
    for (auto &idx : idx2test)
    {
        // Test using both keys
        for (size_t k = 0; k < 2; k++)
        {
            // Fresh mimap
            initialize();

            // Check that element exists
            EXPECT_NO_THROW(m_map.at(m_key1[idx]));
            EXPECT_NO_THROW(m_map.at(m_key2[idx]));

            // Remove element using the corresponding key
            if (k == 0)
            {
                m_map.erase(m_key1[idx]);
            }
            else if (k == 1)
            {
                m_map.erase(m_key2[idx]);
            }

            // Check that element does not exist anymore
            EXPECT_THROW(m_map.at(m_key1[idx]), std::out_of_range);
            EXPECT_THROW(m_map.at(m_key2[idx]), std::out_of_range);
    
            // Check that the rest of the elements remain the same using the first key
            for (size_t k = 0; k < m_key1.size(); k++)
            {
                if (k != idx)
                {
                    ASSERT_EQ(m_map.at(m_key1[k]), m_values[k]);
                }
            }
            // Check that the rest of the elements remain the same using the second key
            for (size_t k = 0; k < m_key2.size(); k++)
            {
                if (k != idx)
                {
                    ASSERT_EQ(m_map.at(m_key2[k]), m_values[k]);
                }
            }

        }
    }
}

TEST_F(MimapTestFixture, begin)
{
    auto it = m_map.begin();
    ASSERT_EQ(it->first_key, m_key1.front());
    ASSERT_EQ(it->second_key, m_key2.front());
    ASSERT_EQ(it->value, m_values.front());
}

TEST_F(MimapTestFixture, end)
{
    auto it = m_map.end() - 1;
    ASSERT_EQ(it->first_key, m_key1.back());
    ASSERT_EQ(it->second_key, m_key2.back());
    ASSERT_EQ(it->value, m_values.back());
}

TEST_F(MimapTestFixture, range)
{
    size_t k = 0;
    for (auto &it : m_map)
    {
        ASSERT_EQ(it.first_key, m_key1[k]);
        ASSERT_EQ(it.second_key, m_key2[k]);
        ASSERT_EQ(it.value, m_values[k]);
        k++;
    }
}