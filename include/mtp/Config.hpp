#pragma once

#include <iostream>
#include <cstdint>

#define MTP_NS_MTP mtp
#define MTP_NAMESPACE namespace MTP_NS_MTP

#define MTP_NS_DETAILS details
#define MTP_NAMESPACE_DETAILS namespace MTP_NS_DETAILS

MTP_NAMESPACE {

using i8 = signed char;
using ui8 = unsigned char;

using i16 = signed short;
using ui16 = unsigned short;

using i32 = signed int;
using ui32 = unsigned int;

using i64 = signed long;
using ui64 = unsigned long;

}