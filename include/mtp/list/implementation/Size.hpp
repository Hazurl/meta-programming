#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>
#include <mtp/list/implementation/List.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename L> 
struct List_size_impl: public i32_<-1> {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::size -- Parameter must be a List"));
};

template<typename...Xs> 
struct List_size_impl<List<Xs...>>  : public i32_<sizeof...(Xs)> {};
    
}

template<typename L>
using size = details::List_size_impl<L>;

template<typename L>
static constexpr i32 size_v = size<L>::value;

}