#pragma once

#include <mtp/Config.hpp>
#include <mtp/list/implementation/List.hpp>

#include <tuple>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename L>
struct List_as_tuple_impl : TConst<void> {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::as_tuple, Parameter must be a list"));
};

template<typename...Args>
struct List_as_tuple_impl<List<Args...>> : TConst<std::tuple<Args...>> {};

}

template<typename L>
using as_tuple = type_of<details::List_as_tuple_impl<L>>;

}