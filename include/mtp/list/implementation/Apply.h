#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>
#include <mtp/list/implementation/List.h>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename template <typename...> F, typename, typename...>
struct applyListArgs_impl;

template<typename template <typename...> F, typename...Args, typename...ArgsF>
struct applyListArgs_impl<List<Args...>> : public TConst<F<Args..., ArgsF...>>{};

template<typename template <typename...> F, typename, typename...>
struct applyArgsListArgs_impl;

template<typename template <typename...> F, typename...Args, typename...ArgsF>
struct applyArgsList_impl<List<Args...>> : public TConst<F<ArgsF..., Args...>>{};

}

template<typename template <typename...> F, typename L>
using applyList = details::applyListArgs_impl<F, L>;

template<typename template <typename...> F, typename L, typename...ArgsF>
using applyListArgs = details::applyListArgs_impl<F, L, ArgsF...>;

template<typename template <typename...> F, typename L, typename...ArgsF>
using applyArgsList = details::applyListArgs_impl<F, ArgsF..., L>;

}