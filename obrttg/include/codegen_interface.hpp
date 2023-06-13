/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 25 Jun 2021
/// @brief Declaration of CodegenInterface virtual class providing a common interface to the Simulink autogenerated software modules.

#ifndef _MBOX_OBRTTG_INCLUDE_CODEGEN_INTERFACE_HPP_
#define _MBOX_OBRTTG_INCLUDE_CODEGEN_INTERFACE_HPP_

namespace obrttg
{

/// @brief Wrapper template interface class for Obrttg codegen components. 
// Derive from this class to define your interface class to model/block code generated by Simulink.
///
/// @tparam Y Model/Block Input structure type
/// @tparam U Model/Block Output structure type
template <typename Y, typename U>
class CodegenInterface
{
public:
    CodegenInterface() = default;
    virtual ~CodegenInterface() = default;

    /// @brief Initializes the internal state variables of the components
    /// 
    /// @returns false upon success, otherwise true
    virtual bool initialize()
    {
        return false;
    }

    /// @brief Triggers an execution step of the codegen component with the provided input. To recover the output of the
    /// component after the execution step, call the `output` method.
    ///
    /// @param[in] U Codegen component input structure
    /// @returns false upon success, otherwise true
    virtual bool step(U)
    {
        return false;
    }

    /// @brief Cleanly terminates the codegen component
    virtual void terminate() {}

    /// @brief Returns the last output of the codegen component.
    ///
    /// @returns Y Output structure after the last execution step
    virtual Y output() const
    {
        return Y{0};
    };
};
} // namespace obrttg

#endif // _MBOX_OBRTTG_INCLUDE_CODEGEN_INTERFACE_HPP_ 