#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename... Xs>
struct List_impl {};

template<typename L>
struct List_is_list_impl : False {};

template<typename...Args>
struct List_is_list_impl<List_impl<Args...>> : True {};

}

template<typename...Xs>
using List = details::List_impl<Xs...>;

template<typename L>
using is_list = details::List_is_list_impl<L>;

template<typename L>
static constexpr bool is_list_v = is_list<L>::value;

}