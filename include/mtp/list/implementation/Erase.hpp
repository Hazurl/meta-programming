#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>
#include <mtp/list/implementation/List.hpp>
#include <mtp/list/implementation/Range.hpp>
#include <mtp/list/implementation/Concat.hpp>

MTP_NAMESPACE {

template<typename L, ui32 P>
using erase = concat<range<L, 0, P>, range<L, P + 1>>;

template<typename L>
using erase_front = range<L, 1>;

template<typename L, ui32 P>
using erase_back = range<L, 1, size<L>::value - 1>;

}