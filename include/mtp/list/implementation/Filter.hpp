#pragma once

#include <mtp/Config.hpp>
#include <mtp/list/implementation/List.hpp>
#include <mtp/list/implementation/Empty.hpp>
#include <mtp/list/implementation/Insert.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<bool insert_it, typename T, typename L>
struct List_filter_impl_insert : TConst< insert_front<L, T> > {}; 

template<typename T, typename L>
struct List_filter_impl_insert<false, T, L> : TConst< L > {}; 
        
template<template<typename T> typename P, typename...Args>
struct List_filter_impl;

template<template<typename T> typename P, typename A, typename...Args>
struct List_filter_impl<P, A, Args...> : List_filter_impl_insert< P<A>::value, A, type_of<List_filter_impl<P, Args...>> > {};

template<template<typename T> typename P>
struct List_filter_impl<P> : TConst<ListEmpty> {};
    
template<template<typename T> typename P, typename L>
struct List_filter_impl_is_list : public TConst<ListEmpty> {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::filter -- Parameter must be a List"));
};

template<template<typename T> typename P, typename...Args>
struct List_filter_impl_is_list<P, List<Args...>> : public List_filter_impl<P, Args...> {};
    
}

template<typename L, template<typename T> typename P>
using filter = type_of<details::List_filter_impl_is_list<P, L>>;

}