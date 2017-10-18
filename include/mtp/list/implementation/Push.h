#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>
#include <mtp/list/implementation/List.h>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename L, typename T>
struct List_push_impl : public TConst<void> {
    static_assert(AlwaysFalse<T>::value, MTP_COLOR(MTP_CB_RED, "List::push -- You can only push to a List"));
};

template<typename T, typename...Args>
struct List_push_impl<List<Args...>, T> : public TConst<List<Args..., T>> {};

}

template<typename L, typename T>
using push = typename details::List_push_impl<L, T>::type;

}