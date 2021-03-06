#pragma once

#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>
#include <mtp/list/implementation/List.hpp>
#include <mtp/list/implementation/Empty.hpp>
#include <mtp/list/implementation/At.hpp>
#include <mtp/list/implementation/Concat.hpp>
#include <mtp/list/implementation/Size.hpp>

MTP_NAMESPACE {
MTP_NAMESPACE_DETAILS {

// impl

template<typename L, ui32 B, ui32 E, ui32 C = 0, 
         bool before_size = (C < size<L>::value), 
         bool after_begin = (C >= B), bool before_end = (C < E)>
struct List_range_impl : public TConst< 
        concat<
            List<at< L, C >>, 
            type_of<List_range_impl<L, B, E, C+1>>
        >
    > {};

template<typename L, ui32 B, ui32 E, ui32 C>
struct List_range_impl<L, B, E, C, true, false, true> : public List_range_impl<L, B, E, C+1> {};

template<typename L, ui32 B, ui32 E, ui32 C>
struct List_range_impl<L, B, E, C, true, true, false> : public TConst<ListEmpty> {};

template<typename L, ui32 B, ui32 E, ui32 C, bool after, bool before>
struct List_range_impl<L, B, E, C, false, after, before> : public TConst<ListEmpty> {};

// B <= E ?

template<typename L, ui32 B, ui32 E, bool good = (B <= E)>
struct List_range_impl_check_index : public List_range_impl<L, B, E> {};

template<typename L, ui32 B, ui32 E>
struct List_range_impl_check_index<L, B, E, false> : public TConst<ListEmpty> {};

// Is List ?

template<typename T, ui32 B, ui32 E>
struct List_range_impl_is_list : public TConst<ListEmpty> {
    static_assert(AlwaysFalse<T>::value, MTP_COLOR(MTP_CB_RED, "List::range -- Parameter must be a List"));
};

template<typename...Args, ui32 B, ui32 E>
struct List_range_impl_is_list<List<Args...>, B, E> : public List_range_impl_check_index<List<Args...>, B, E> {};

}

template<typename L, ui32 Begin, ui32 End = -1>
using range = type_of<details::List_range_impl_is_list<L, Begin, End>>;

template<typename L, ui32 I>
using before = range<L, 0, I>;

template<typename L, ui32 I>
using after = range<L, I + 1>;

}