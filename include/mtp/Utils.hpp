#pragma once

#include <mtp/Config.hpp> 
#include <mtp/Macro.hpp>

#define MTP_STATIC_ERROR(template, msg) \
    static_assert(AlwaysFalse<template>::value, MTP_COLOR(MTP_CB_RED, msg))
#define MTP_STATIC_ASSERT(cond, msg) \
    static_assert(cond, MTP_COLOR(MTP_CB_RED, msg))

MTP_NAMESPACE {
    
template<typename T, T t>
struct Constant {
    static constexpr T value = t;
};

template<i32 v>
using i32Const = Constant<i32, v>;

template<bool b>
using boolConst = Constant<bool, b>;

template<typename T>
struct TConst {
    using type = T;
};

template<typename...>
struct ShowType;

template<typename...>
struct AlwaysFalse {
    static constexpr bool value = false;
};

template<typename T>
using type_of = typename T::type;

}