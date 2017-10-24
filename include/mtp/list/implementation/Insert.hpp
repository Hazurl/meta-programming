#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>
#include <mtp/list/implementation/List.hpp>
#include <mtp/list/implementation/Range.hpp>
#include <mtp/list/implementation/Concat.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename L, typename T>
struct List_insert_front_impl : public TConst<void> {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::insert -- Parameter must be a List"));
};

template<typename...Args, typename T>
struct List_insert_front_impl<List<Args...>, T> : public TConst<List<T, Args...>> {};

template<typename L, typename T>
struct List_insert_back_impl : public TConst<void> {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::insert -- Parameter must be a List"));
};

template<typename...Args, typename T>
struct List_insert_back_impl<List<Args...>, T> : public TConst<List<Args..., T>> {};

template<typename L, typename T>
struct List_insert_back_range_impl : public TConst<void> {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::insert -- Parameters must be Lists"));
};

template<typename...Args, typename...Trgs>
struct List_insert_back_range_impl<List<Args...>, List<Trgs...>> : public TConst<List<Args..., Trgs...>> {};

}

template<typename L, typename T>
using insert_front = type_of<details::List_insert_front_impl<L, T>>;

template<typename L, typename T>
using insert_back = type_of<details::List_insert_back_impl<L, T>>;

template<typename L, typename T, ui32 P>
using insert = concat<insert_back<range<L, 0, P>, T>, range<L, P>>;

template<typename L, typename T, ui32 P>
using insert_range = concat<type_of<details::List_insert_back_range_impl<range<L, 0, P>, T>>, range<L, P>>;

}