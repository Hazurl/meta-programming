#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>
#include <mtp/list/implementation/List.h>
#include <mtp/list/implementation/Size.h>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<i32 N, typename>
struct List_at_impl;

template<i32 N, typename...Args>
struct List_at_args_impl;

template<i32 N, typename...Args>
struct List_at_impl<N, List<Args...>> : public TConst<typename List_at_args_impl<N, Args...>::type > {
    static_assert(N >= 0 && N < size<List<Args...>>::value, "List::at -- Out of bounds, the index is too high");
};

template<i32 N, typename A, typename...Args>
struct List_at_args_impl<N, A, Args...> : public TConst<typename List_at_args_impl<N-1, Args...>::type > {};

template<typename A, typename...Args> 
struct List_at_args_impl<0, A, Args...>  : public TConst<A> {};

}

template<typename L, ui32 N>
using at = typename details::List_at_impl<N, L>::type;

template<typename L>
using first = at<L, 0>;

template<typename L>
using last = at<L, size<L>::value - 1>;

}