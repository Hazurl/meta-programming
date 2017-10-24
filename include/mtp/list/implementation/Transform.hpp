#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>
#include <mtp/list/implementation/List.h>
#include <mtp/list/implementation/Insert.h>
#include <mtp/list/implementation/Empty.h>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<template<typename> typename F, typename T>
struct List_transform_one_impl : public TConst<F<T>> {};

template<template<typename> typename F, typename...Args>
struct List_transform_all_impl;

template<template<typename> typename F, typename A, typename...Args>
struct List_transform_all_impl<F, A, Args...> : public TConst<insert_front<type_of<List_transform_all_impl<F, Args...>>, F<A>>> {};

template<template<typename> typename F>
struct List_transform_all_impl<F> : public TConst<ListEmpty> {};

template<template<typename> typename F, typename L>
struct List_transform_impl_is_list : public TConst<void> {
    static_assert(AlwaysFalse<L>::value, "List::transform, Parameter must be a list");
};

template<template<typename> typename F, typename...Args>
struct List_transform_impl_is_list<F, List<Args...>> : public TConst<type_of<List_transform_all_impl<F, Args...>>> {};

}

template<typename L, template<typename> typename F>
using transform = type_of<details::List_transform_impl_is_list<F, L>>;

}