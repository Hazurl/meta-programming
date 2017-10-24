#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>
#include <mtp/list/implementation/List.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename> struct List_empty_impl;

template<typename...Xs> 
struct List_empty_impl<List<Xs...>>  : public boolConst<false> {};

template<> 
struct List_empty_impl<List<>> : public boolConst<true> {};
    
}

template<typename L>
using empty = details::List_empty_impl<L>;

template<typename L>
static constexpr bool empty_v = empty<L>::value;

using ListEmpty = List<>;

}