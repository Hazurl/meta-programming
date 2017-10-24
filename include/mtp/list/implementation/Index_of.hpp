#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>
#include <mtp/list/implementation/List.hpp>
#include <mtp/list/implementation/Size.hpp>

#include <type_traits>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

// Flat Args

template<i32 I, typename T, typename...Args>
struct List_index_of_impl_args : public i32Const<I> {};

template<i32 I, typename T, typename A, typename...Args>
struct List_index_of_impl_args<I, T, A, Args...> : public i32Const<List_index_of_impl_args<I+1, T, Args...>::value> {};

template<i32 I, typename T> 
struct List_index_of_impl_args<I, T> : public i32Const<-1> {};

// Is List ?

template<typename L, typename T>
struct List_index_of_impl_is_list : public TConst<void> {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::index_of -- Parameter must be a List"));
};

template<typename...Args, typename T>
struct List_index_of_impl_is_list<List<Args...>, T> : public List_index_of_impl_args<0, T, Args...> {};

// Impl

template<typename L, typename T>
using List_index_of_impl = List_index_of_impl_is_list<L, T>;

}

template<typename L, typename T>
using index_of = details::List_index_of_impl<L, T>;

template<typename L, typename T>
static constexpr i32 index_of_v = index_of<L, T>::value;

}