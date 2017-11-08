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

#define USING_CONST(T) template<T v> using T ## _ = Constant<T, v>;
    USING_CONST(i64)
    USING_CONST(ui64)
    USING_CONST(i32)
    USING_CONST(ui32)
    USING_CONST(i16)
    USING_CONST(ui16)
    USING_CONST(i8)
    USING_CONST(ui8)
    USING_CONST(bool)
#undef USING_CONST

using False = bool_<false>;
using True = bool_<true>;

template<typename T>
struct TConst {
    using type = T;
};

template<typename...>
struct ShowType;

template<typename...>
using Nothing = void;

template<typename...>
struct AlwaysFalse {
    static constexpr bool value = false;
};

template<typename T>
using type_of = typename T::type;

MTP_NAMESPACE_DETAILS {

template<bool use_a, typename A, typename B>
struct switch_t_impl : public TConst<A> {};
template<typename A, typename B>
struct switch_t_impl<false, A, B> : public TConst<B> {};
    
}

template<bool use_first_type, typename A, typename B>
using switch_t = type_of<details::switch_t_impl<use_first_type, A, B>>;

template<typename T>
using add_const = const T;

template<typename T>
using add_ptr = T*;

template<typename T>
using add_ref = T&;

template<bool put_const, typename T>
using add_const_if = switch_t<put_const, add_const<T>, T>;

template<bool put_ptr, typename T>
using add_ptr_if = switch_t<put_ptr, add_ptr<T>, T>;

template<bool put_ref, typename T>
using add_ref_if = switch_t<put_ref, add_ref<T>, T>;

}