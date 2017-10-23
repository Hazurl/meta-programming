#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>
#include <mtp/list/implementation/List.h>
#include <mtp/list/implementation/Insert.h>
#include <mtp/list/implementation/Empty.h>
#include <mtp/list/implementation/At.h>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<template<typename> typename F, typename T>
struct transform_one_impl : public TConst<F<T>> {};

template<template<typename> typename F, typename...Args>
struct transform_all_impl;

template<template<typename> typename F, typename A, typename...Args>
struct transform_all_impl<F, A, Args...> : public TConst<insert_front<typename transform_all_impl<F, Args...>::type, F<A>>> {};

template<template<typename> typename F>
struct transform_all_impl<F> : public TConst<ListEmpty> {};

template<typename T>
struct apply_lambda_one_impl {
    constexpr apply_lambda_one_impl () = default;

    template<typename F, typename Ret = void>
    constexpr Ret operator () (F && f) {
        return f(TConst<T>{});
    }
};

template<typename...Args>
struct apply_lambda_all_impl;

template<typename A, typename...Args>
struct apply_lambda_all_impl<A, Args...> {
    constexpr apply_lambda_all_impl () = default;

    template<typename F>
    constexpr void operator () (F && f) {
        apply_lambda_one_impl<A>{}(std::forward<F>(f));
        apply_lambda_all_impl<Args...>{}(std::forward<F>(f));
    }
};

template<>
struct apply_lambda_all_impl<> {
    constexpr apply_lambda_all_impl () = default;

    template<typename F>
    constexpr void operator () (F &&) {}
};

}

template<typename L>
struct apply_lambda {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::apply_lambda -- Parameter must be a List"));
};

template<typename...Args>
struct apply_lambda<List<Args...>> {
    constexpr apply_lambda () = default;

    template<typename F>
    constexpr void operator () (F && f) const {
        details::apply_lambda_all_impl<Args...>{}(std::forward<F>(f));
    }
};

}