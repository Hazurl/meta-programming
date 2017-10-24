#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>

MTP_NAMESPACE {
namespace func {

template<typename T, T a, T b>
using plus = Constant<T, a+b>;

template<typename T, T a, T b>
using substract = Constant<T, a-b>;

template<typename T, T a, T b>
using substract_inv = Constant<T, b-a>;

template<typename T, T a, T b>
using multiply = Constant<T, a*b>;

template<typename T, T a, T b>
using divide = Constant<T, a/b>;

template<typename T, T a, T b>
using divide_inv = Constant<T, b/a>;

template<typename T, T a, T b>
using modulo = Constant<T, a%b>;

template<typename T, T a, T b>
using modulo_inv = Constant<T, b%a>;

template<typename T, T a, T b>
using all = Constant<T, a && b>;

template<typename T, T a, T b>
using any = Constant<T, a || b>;

template<typename T, T a, T b>
using none = Constant<T, !(a || b)>;

template<typename T, T a, T b>
using not_all = Constant<T, !(a && b)>;

template<typename T, T a>
using negate = Constant<T, -a>;

template<typename T, T a>
using inverse = Constant<T, 1/a>;

template<typename T, T a>
using opposite = Constant<T, !a>;

template<typename T, T a>
using inc = Constant<T, a+1>;

template<typename T, T a>
using dec = Constant<T, a-1>;

}}