#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>
#include <mtp/list/implementation/List.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename L> 
struct List_empty_impl : False {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::empty -- Parameter must be a List"));    
};

template<typename...Xs> 
struct List_empty_impl<List<Xs...>>  : public False {};

template<> 
struct List_empty_impl<List<>> : public True {};
    
}

template<typename L>
using empty = details::List_empty_impl<L>;

template<typename L>
static constexpr bool empty_v = empty<L>::value;

using ListEmpty = List<>;

}