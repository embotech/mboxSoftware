/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 29 Jun 2021
/// @brief Declararion of DynBitSet, DataPackace and derived helper classes to support the Mavlink communication interface.

#ifndef _MBOX_COMMUNICATION_INCLUDE_MAVLINK_TOOLS_HPP_
#define _MBOX_COMMUNICATION_INCLUDE_MAVLINK_TOOLS_HPP_

#include <map>
#include <string>
#include <bitset>
#include <array>
#include <chrono>
#include <algorithm>

#include "mimap.hpp"
#include "time_utils.hpp"
#include "obrttg_input_parser.hpp"

#ifndef INCAS_LIB_H
struct signal_t;
#endif

namespace obrttg::mavlink
{

typedef embo::mimap<uint32_t, std::string, std::size_t> SignalMap;
class DynBitSet : public std::vector<bool>
{
public:
    DynBitSet() = default;
    DynBitSet(size_t n)
    {
        resize(n);
    }

    bool any() const
    {
        return (std::find(this->begin(), this->end(), true) != this->end());
    }

    bool test(size_t pos) const
    {
        return operator[](pos);
    }

    DynBitSet& set()
    {
        for (size_t i = 0; i < size(); i++)
        {
            operator[](i) = true;
        }
        return *this;
    }

    DynBitSet& set(size_t pos, bool val = true)
    {
        
        operator[](pos) = val;
        return *this;
    }

    DynBitSet& reset()
    {
        for (size_t i = 0; i < size(); i++)
        {
            operator[](i) = false;
        }
        return *this;
    }

    DynBitSet& reset(size_t pos)
    {
        operator[](pos) = false;
        return *this;
    }

};

class DataPackage
{
public:
    DataPackage() = delete;
    DataPackage(const DataPackage&) = delete;
    DataPackage(DataPackage&&) = default;
    DataPackage(size_t size, const double &maxAge, const SignalMap &map);

    ~DataPackage() = default;

    /// @brief Returns the maximum allowed age difference between signals in the data package
    uint64_t maxAgeDiff() const
    {
        return m_maxAgeDiff;
    }

    /// @brief Returns the timestamp of the data package (the timestamp of the oldest signal)
    uint64_t timestamp() const
    {
        return m_timestamp;
    }

    /// @brief Returns const pointer to signal array
    const std::unique_ptr<const signal_t>* data() const
    {
        return m_signals.data();
    }

    /// @brief Returns true if the data package is complete
    bool full() const
    {
        return (m_bset == DynBitSet(m_bset.size()).set());
    }

    /// @brief Returns the number of signals in the data package
    std::size_t size() const
    {
        return m_signals.size();
    }

    /// @brief Checks if the data package contains any signal
    ///
    /// @return True if it contains any signal, otherwise false
    bool empty() const
    {
        return !(m_bset.any());
    }

    /// @brief Checks if a signal id belongs to the data package
    ///
    /// @return True if the signal belongs to the data package, otherwise false
    bool exist(const uint32_t &sigId) const
    {
        return (m_map.find(sigId) != m_map.end());
    }

    /// @brief Checks if a signal name belongs to the data package
    ///
    /// @return True if the signal belongs to the data package, otherwise false
    bool exist(const std::string &sigName) const
    {
        return (m_map.find(sigName) != m_map.end());
    }

    /// @brief Checks if a signal has already being added to the data package
    ///
    /// @return True if the data package already contains the signal, otherwise false
    bool contains(uint32_t sigId) const
    {
        if (exist(sigId))
        {
            return m_bset.test(m_map.at(sigId));
        }
        return false;
    }

    /// @brief Returns a const reference to the signal at position idx in the data package.
    const signal_t& operator[] (const std::size_t &idx) const
    {
        return *m_signals.at(idx).get();
    }

    /// @brief Returns a const reference to the signal named 'name' in the data package.
    const signal_t& operator[] (const std::string &name) const
    {
        return *m_signals.at(m_map.at(name)).get();
    }

    /// @brief Returns a const reference to the signal identified by 'id' in the data package.
    const signal_t& operator[] (const uint32_t &id) const
    {
        return *m_signals.at(m_map.at(id)).get();
    }
    /// @brief Returns an iterator pointing to the first signal in the data package.
    auto begin() const
    {
        return m_signals.begin();
    }

    /// @brief Returns an iterator referring to the past-the-end signal in the data package.
    auto end() const
    {
        return m_signals.end();
    }

    /// @brief Resets contents of the data package
    void reset();

    /// @brief Checks if a signal is valid to be added to the data package
    ///
    /// @param[in] signal the signal to be checked
    ///
    /// @return 0 if it is good to be added;
    ///         1 if it does not belong to the data package
    ///         2 if it was already added to the data package
    ///         3 if it is too old
    ///         4 if it is too new
    int check(const std::unique_ptr<const signal_t> &s) const;

    /// @brief Inserts signal to the data package
    ///
    /// @param[in]
    ///
    /// @return 0 if the signal was added successfully;
    ///         1 if the signal does not belong to the data package.
    ///         2 was already added to the data package;
    ///         3 if it is too old
    ///         4 if it is too new
    int insert(std::unique_ptr<const signal_t> signal);

protected:
    const size_t m_size;
    const double m_maxAgeDiff;                  ///< Maximum age difference between signals in the same package
    const SignalMap m_map;                      ///< Map of signal IDs and indices in the signal array

    uint64_t m_timestamp;                                       ///< Timestamp of the data package in [us]
    std::vector<std::unique_ptr<const signal_t>> m_signals;     ///< Array of signals composing the data package
    DynBitSet m_bset;                                           ///< Bitset keeping track of the added signals
};

static constexpr uint64_t MAX_AGE_DIFF = 20000;     ///< Maximum age difference between signals in the same package

// Rx package size definition
static constexpr std::size_t RX_N_SIGNALS = 17;     ///< Number of signals in a Rx data package

// Tx package size definition
static constexpr std::size_t TX_N_SIGNALS = 8;      ///< Number of signals in a Tx data package

class RxPackage : public DataPackage
{
public:
    RxPackage();
};

struct DTVState 
{
    DTVState() = default;
    DTVState(const RxPackage &rxPkg);

    operator RxPackage() const;
    operator busGncCommIn() const;

    double timestamp;       // Package timestamp in seconds
    busPACinput data;
};

class TxPackage : public DataPackage
{
public:
    TxPackage();
};

struct DTVReference 
{
    DTVReference() = default;
    DTVReference(const TxPackage &txPkg);

    operator TxPackage() const;

    double timestamp;   // Reference timestamp in seconds
    int pacStatus;
    double position[3];
    double velocity[3];
};

} // namespace obrttg::mavlink
#endif  // _MBOX_COMMUNICATION_INCLUDE_MAVLINK_TOOLS_HPP_