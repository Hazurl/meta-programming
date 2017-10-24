#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>
#include <mtp/list/implementation/List.hpp>
#include <mtp/list/implementation/Insert.hpp>
#include <mtp/list/implementation/Empty.hpp>
#include <mtp/list/implementation/At.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

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