#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>

#include <mtp/list/implementation/Transform.hpp>
#include <mtp/list/implementation/Func.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename T, template<typename, T, T> typename F, T t, typename...Args>
struct List_fold_impl;

template<typename T, template<typename, T, T> typename F, T t, typename A, typename...Args>
struct List_fold_impl<T, F, t, A, Args...> : List_fold_impl<T, F, F<T, t, A::value>::value, Args...> {};
        
template<typename T, template<typename, T, T> typename F, T t>
struct List_fold_impl<T, F, t> : Constant<T, t> {};

template<typename T, template<typename, T, T> typename F, T t, typename L>
struct List_fold_impl_is_list : public Constant<T, t> {
    static_assert(AlwaysFalse<L>::value, MTP_COLOR(MTP_CB_RED, "List::fold -- Parameter must be a List"));
};

template<typename T, template<typename, T, T> typename F, T t, typename...Args>
struct List_fold_impl_is_list<T, F, t, List<Args...>> : public List_fold_impl<T, F, t, Args...> {};

}

template<typename L, typename Ret, Ret Start, template<typename, Ret, Ret> typename F>
using fold = details::List_fold_impl_is_list<Ret, F, Start, L>;

template<typename L>
using all = fold<L, bool, true, func::all>;

template<typename L>
using all = fold<L, bool, true, func::all>;

template<typename L>
using not_all = fold<L, bool, true, func::not_all>;

template<typename L>
using none = fold<L, bool, false, func::none>;

template<typename L, typename Ret = i32>
using sum = fold<L, Ret, 0, func::plus>;

}