#pragma once

#include <mtp/Config.hpp>
#include <mtp/random/Seed.hpp>

MTP_NAMESPACE {
    /*
template<ui64 S, ui64 A = 6364136223846793005ULL, ui64 C = 165465466027ULL, ui64 M = (1 << 31) - 1>
class LinearRandom {
public:
    static constexpr ui64 state = (S * A + C) % M;
    static constexpr ui64 value = state;
    using next = LinearRandom<state, A, C, M>;

    struct Split {
        using Gen1 = LinearRandom<state,             A*A, C, M>;
        using Gen2 = LinearRandom<next::state,       A*A, C, M>;
        using Gen3 = LinearRandom<next::next::state, A*A, C, M>;
    };
};

template<ui32 N, typename R>
struct RandomHelper {
    static constexpr ui64 value = typename RandomHelper<N-1, typename R::next>::value;
};

template<typename R>
struct RandomHelper<0, R> {
    static constexpr ui64 value = typename R::value;
};

template<ui32 N, typename Seed = Seed_Time, typename R = LinearRandom<Seed::value>>
static constexpr ui64 Random = typename RandomHelper<N, R>::value;
*/

}