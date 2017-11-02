#pragma once

#include <mtp/Config.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<i32 N, typename T, typename...Args>
struct List_count_impl_args;

template<i32 N, typename T, typename A, typename...Args>
struct List_count_impl_args<N, T, A, Args...> : public i32Const<List_count_impl_args<N, T, Args...>::value> {};

template<i32 N, typename T, typename...Args>
struct List_count_impl_args<N, T, T, Args...> : public i32Const<List_count_impl_args<N+1, T, Args...>::value> {};

template<i32 N, typename T>
struct List_count_impl_args<N, T> : public i32Const<N> {};

// Is List ?

template<typename T, typename L>
struct List_count_impl_is_list : public TConst<void> {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::count -- Parameter must be a List"));
};

template<typename T, typename...Args>
struct List_count_impl_is_list<T, List<Args...>> : public List_count_impl_args<0, T, Args...> {};
    
}

template<typename L, typename T>
using count = details::List_count_impl_is_list<T, L>;

template<typename L, typename T>
static constexpr i32 count_v = count<L, T>::value;

}