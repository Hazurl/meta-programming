#pragma once

#include <mtp/Config.h>
#include <mtp/Utils.h>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename... Xs>
struct List_impl {};    

}

template<typename...Xs>
using List = details::List_impl<Xs...>;

}