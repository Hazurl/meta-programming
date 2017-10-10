#pragma once

#include <iostream>
#include <cstdint>

#define MTP_NS mtp
#define BEGIN_MTP_NS namespace mtp {
#define END_MTP_NS }

#define MTP_DETAILS_NS details
#define BEGIN_MTP_DETAILS_NS BEGIN_MTP_NS namespace details {
#define END_MTP_DETAILS_NS } END_MTP_NS

BEGIN_MTP_NS

using i8 = signed char;
using ui8 = unsigned char;

using i16 = signed short;
using ui16 = unsigned short;

using i32 = signed int;
using ui32 = unsigned int;

using i64 = signed long;
using ui64 = unsigned long;

END_MTP_NS