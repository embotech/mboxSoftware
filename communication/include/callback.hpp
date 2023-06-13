/*
 *  (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
 */

/// @file
/// @author embotech AG
/// @date 15 Jun 2021
/// @brief Declaration of the Callback template struct providing a wrapper to convert C++ non-static member functions into C callback functions.

#ifndef _MBOX_UTILS_INCLUDE_CALLBACK_HPP_
#define _MBOX_UTILS_INCLUDE_CALLBACK_HPP_

#include <functional>

/// The implementation is copied from this StackOverflow thread
/// https://stackoverflow.com/a/29817048
/// and the modifications to be able to create more than one callback were taken from this other thread
/// https://stackoverflow.com/questions/66474621/multiple-non-static-callbacks-of-c-member-functions

template <typename T, int tag = 0>
struct Callback;

template <typename Ret, typename... Params, int tag>
struct Callback<Ret(Params...), tag> {
   template <typename... Args> 
   static Ret callback(Args... args) {                    
      return func(args...);  
   }
   int m_tag = tag;
   static std::function<Ret(Params...)> func; 
};

template <typename Ret, typename... Params, int tag>
std::function<Ret(Params...)> Callback<Ret(Params...), tag>::func;

#endif
