#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>
#include <mtp/list/implementation/List.h>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename K, typename L>
struct List_concat_impl : public TConst<void> {
    static_assert(AlwaysFalse<K>::value, MTP_COLOR(MTP_CB_RED, "List::concat -- Parameters must be Lists"));
};

template<typename...Krgs, typename...Lrgs>
struct List_concat_impl<List<Krgs...>, List<Lrgs...>> : public TConst<List<Krgs..., Lrgs...>> {};

}

template<typename L0, typename L1>
using concat = typename details::List_concat_impl<L0, L1>::type;

}