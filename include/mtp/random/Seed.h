#pragma once

#include <mtp/Config.h>

BEGIN_MTP_NS

static constexpr ui64 get_Seed_Time() {
    ui64 value = 0;
    for(auto const& c : __TIME__) {
        value <<= 8;
        value |= c;
    }
    return value;
}


template<ui64 _value>
class Seed_Fixed {
public:    
    static constexpr ui64 value = _value;
};

using Seed_Time = Seed_Fixed<get_Seed_Time()>;
using Seed = Seed_Time;

END_MTP_NS