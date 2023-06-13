/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 29 Jun 2021
/// @brief Declaration of mimap template class, a multi-index map container.

#ifndef _UTILS_CONTAINERS_INCLUDE_MIMAP_HPP_
#define _UTILS_CONTAINERS_INCLUDE_MIMAP_HPP_

#include <algorithm>
#include <vector>
#include <map>
#include <tuple>

namespace embo
{
template<class K1, class K2, class V>
class mimap
{
public:
    struct Entry {
        K1 first_key;
        K2 second_key;
        V value;
    };

    typedef std::vector<Entry> Data;

    mimap()
    {
        clear();
    }

    mimap(const std::vector<std::tuple<K1, K2, V>> &entries) : mimap()
    {
        for (auto &entry : entries)
        {
            insert(entry);
        }
    }

    ~mimap() = default;

    bool insert(const std::tuple<K1, K2, V> &entry)
    {
        if ((m_key1.find(std::get<0>(entry)) == m_key1.end()) &&
            (m_key2.find(std::get<1>(entry)) == m_key2.end()))
        {   
            m_data.push_back(Entry{std::get<0>(entry), std::get<1>(entry), std::get<2>(entry)});
            m_key1.insert(std::pair<K1, size_t>(std::get<0>(entry), m_data.size()-1));
            m_key2.insert(std::pair<K2, size_t>(std::get<1>(entry), m_data.size()-1));
            return true;
        }
        else
        {
            return false;
        }
    }

    const V& operator[] (const K1 &key)
    {
        return m_data[m_key1[key]].value;
    }

    const V& operator[] (const K2 &key)
    {
        return m_data[m_key2[key]].value;
    }

    const V& at(const K1 &key) const
    {
        return m_data.at(m_key1.at(key)).value;
    }

    const V& at(const K2 &key) const
    {
        return m_data.at(m_key2.at(key)).value;
    }

    std::size_t size() const
    {
        return m_data.size();
    }

    auto find(const K1 &key) const
    {
        if (m_key1.find(key) != m_key1.end())
        {
            return m_data.begin() + m_key1.at(key);
        }
        else
        {
            return m_data.end();
        }
    }

    auto find(const K2 &key) const
    {
        if (m_key2.find(key) != m_key2.end())
        {
            return m_data.begin() + m_key2.at(key);
        }
        else
        {
            return m_data.end();
        }
    }

    auto begin() const
    {
        return m_data.begin();
    }

    auto end() const
    {
        return m_data.end();
    }

    void erase(const K1 &key)
    {
        if (m_key1.find(key) != m_key1.end())
        {
            auto idx = m_key1.at(key);
            for (auto &p : m_key1)
            {
                p.second = (p.second > idx) ? (p.second-1) : p.second;
            }
            for (auto &p : m_key2)
            {
                p.second = (p.second > idx) ? (p.second-1) : p.second;
            }

            m_key1.erase(m_data.at(idx).first_key);
            m_key2.erase(m_data.at(idx).second_key); 
            m_data.erase(m_data.begin()+idx);
        }
    }

    void erase(const K2 &key)
    {
        if (m_key2.find(key) != m_key2.end())
        {
            auto idx = m_key2[key];
            for (auto &p : m_key1)
            {
                p.second = (p.second > idx) ? (p.second-1) : p.second;
            }
            for (auto &p : m_key2)
            {
                p.second = (p.second > idx) ? (p.second-1) : p.second;
            }
            m_key1.erase(m_data.at(idx).first_key);
            m_key2.erase(m_data.at(idx).second_key); 
            m_data.erase(m_data.begin()+idx);
        }
    }

    void clear()
    {
        m_key1.clear();
        m_key2.clear();
        m_data.clear();
    }

private:
    Data m_data;
    std::map<K1, size_t> m_key1;
    std::map<K2, size_t> m_key2;
};

} // namespace embo

#endif // _UTILS_CONTAINERS_INCLUDE_MIMAP_HPP_