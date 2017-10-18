#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>
#include <mtp/list/implementation/List.h>
#include <mtp/list/implementation/Size.h>

#include <type_traits>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

// Flat Args

template<i32 N, typename...Args>
struct List_at_impl_args;

template<i32 N, typename A, typename...Args>
struct List_at_impl_args<N, A, Args...> : public TConst<typename List_at_impl_args<N-1, Args...>::type > {};

template<typename A, typename...Args> 
struct List_at_impl_args<0, A, Args...>  : public TConst<A> {};

// Index in range [0, size[ ?

template<bool, i32 N, typename...Args>
struct List_at_impl_check_index : public TConst<typename List_at_impl_args<N, Args...>::type > {};

template<i32 N, typename...Args>
struct List_at_impl_check_index<false, N, Args...> : public TConst<void> {
    MTP_STATIC_ASSERT(
        (N >= 0 && N < size<List<Args...>>::value), 
        "List::at -- Out of bounds, the index is too high");
};

// Is List ?

template<i32 N, typename T>
struct List_at_impl_is_list : public TConst<void> {
    MTP_STATIC_ERROR(T, "List::at -- Parameter must be a List");
};

template<i32 N, typename...Args>
struct List_at_impl_is_list<N, List<Args...>> : public List_at_impl_check_index<(N >= 0 && N < size<List<Args...>>::value), N, Args...> {};

// Impl

template<typename L, i32 N>
using List_at_impl = List_at_impl_is_list<N, L>;

}

template<typename L, ui32 N>
using at = typename details::List_at_impl<L, N>::type;

template<typename L>
using first = at<L, 0>;

template<typename L>
using last = at<L, size<L>::value - 1>;

}