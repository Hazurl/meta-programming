#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>
#include <mtp/list/implementation/List.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename T>
struct List_flatten_impl_flat : TConst<List<T>> {};

template<typename...Args>
struct List_flatten_impl_flat<List<Args...>> : TConst<List<Args...>> {};

template<typename L>
struct List_flatten_impl : TConst<void> {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::flatten, parameter must be a list"));
};

template<typename A, typename...Args>
struct List_flatten_impl<List<A, Args...>> : TConst<
    concat<
        type_of<List_flatten_impl_flat<A>>, 
        type_of<List_flatten_impl<List<Args...>>>
    >
> {};

template<typename A>
struct List_flatten_impl<List<A>> : List_flatten_impl_flat<A> {};

template<>
struct List_flatten_impl<List<>> : TConst<List<>> {};

}

template<typename L>
using flatten = type_of<details::List_flatten_impl<L>>;

}