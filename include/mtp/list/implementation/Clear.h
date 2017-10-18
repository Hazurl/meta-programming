#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>
#include <mtp/list/implementation/List.h>
#include <mtp/list/implementation/Empty.h>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename T>
struct List_clear_impl : public TConst<void> {
    static_assert(AlwaysFalse<T>::value, MTP_COLOR(MTP_CB_RED, "List::clear -- Not a List"));
};

template<typename...Args>
struct List_clear_impl<List<Args...>> : public TConst<ListEmpty> {};

}

template<typename L>
using clear = typename details::List_clear_impl<L>::type;

}