#pragma once
#include <mtp/Config.h> 

BEGIN_MTP_NS

template<typename T, T t>
struct Constant {
    static constexpr T value = t;
};

template<i32 v>
using i32Const = Constant<i32, v>;

template<bool b>
using boolConst = Constant<bool, b>;

template<typename...>
class ShowType;

END_MTP_NS