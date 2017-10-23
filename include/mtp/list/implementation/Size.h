#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>
#include <mtp/list/implementation/List.h>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename> struct List_size_impl;

template<typename...Xs> 
struct List_size_impl<List<Xs...>>  : public i32Const<sizeof...(Xs)> {};
    
}

template<typename L>
using size = details::List_size_impl<L>;

template<typename L>
static constexpr i32 size_v = size<L>::value;

}