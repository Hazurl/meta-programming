#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>

BEGIN_MTP_NS
BEGIN_MTP_DETAILS_NS

template<typename... Xs>
struct List_impl {};

END_MTP_DETAILS_NS

template<typename...Xs>
using List = mtp::details::List_impl<Xs...>;

BEGIN_MTP_DETAILS_NS

template<typename...> struct List_size_impl;
template<typename X> 
struct List_size_impl<List<X>>  : public i32Const<1> {};
template<typename X, typename...Xs> 
struct List_size_impl<List<X, Xs...>>  : public i32Const<1+List_size_impl<List<Xs...>>::value> {};

END_MTP_DETAILS_NS

template<typename L>
using size = mtp::details::List_size_impl<L>;

BEGIN_MTP_DETAILS_NS

template<typename...> struct List_empty_impl;
template<typename...Xs> 
struct List_empty_impl<List<Xs...>>  : public boolConst<false> {};
template<> 
struct List_empty_impl<List<>> : public boolConst<true> {};

END_MTP_DETAILS_NS

template<typename L>
using empty = mtp::details::List_empty_impl<L>;

END_MTP_NS