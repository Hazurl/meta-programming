#pragma once
#include <mtp/Config.h> 

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

}