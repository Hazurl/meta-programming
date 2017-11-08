#pragma once

#include <mtp/Config.hpp>
#include <mtp/list/implementation/List.hpp>
#include <mtp/list/implementation/Count.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename...Args>
struct List_unique_impl;

template<typename A, typename...Args>
struct List_unique_impl<A, Args...> : bool_<(count_v<List<Args...>, A> == 0) && List_unique_impl<Args...>::value> {};

template<>
struct List_unique_impl<> : True {};

template<typename L>
struct List_unique_impl_is_list : public False {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::unique -- Parameter must be a List"));
};

template<typename...Args>
struct List_unique_impl_is_list<List<Args...>> : public List_unique_impl<Args...> {};

}

template<typename L>
using unique = details::List_unique_impl_is_list<L>;

template<typename L>
static constexpr bool unique_v = unique<L>::value;

}