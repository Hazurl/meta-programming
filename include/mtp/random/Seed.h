#include <mtp/config.h>

BEGIN_MTP_NS

class Seed_Time {
public:
    static constexpr ui64 get() {
        ui64 value = 0;
        for(auto const& c : __TIME__) {
            value ^= c;
            value <<= 8;
            value |= c;
            }
        return value;
    }
};

template<ui64 value>
class Seed_Fixed {
public:
    static constexpr ui64 get() {
        return value;
    }
};

using Seed = Seed_Time;

END_MTP_NS