#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>
#include <mtp/list/implementation/List.h>

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