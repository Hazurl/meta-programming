#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>
#include <mtp/list/implementation/List.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename K, typename L>
struct List_concat_impl_two : public TConst<void> {
    static_assert(AlwaysFalse<K>::value, MTP_COLOR(MTP_CB_RED, "List::concat -- Parameters must be Lists"));
};

template<typename...Krgs, typename...Lrgs>
struct List_concat_impl_two<List<Krgs...>, List<Lrgs...>> : public TConst<List<Krgs..., Lrgs...>> {};


template<typename L0, typename...Lists>
struct List_concat_impl : TConst<L0> {};

template<typename L0, typename L1, typename...Lists>
struct List_concat_impl<L0, L1, Lists...> : List_concat_impl<type_of<List_concat_impl_two<L0, L1>>, Lists...> {};

}

template<typename...Lists>
using concat = type_of<details::List_concat_impl<Lists...>>;

}