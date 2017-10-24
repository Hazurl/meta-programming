#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

template<typename... Xs>
struct List_impl {};    

}

template<typename...Xs>
using List = details::List_impl<Xs...>;

}