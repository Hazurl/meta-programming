#include <mtp/Config.hpp>
#include <mtp/Utils.hpp>

#include <mtp/random/Seed.hpp>
#include <mtp/random/Random.hpp>

#include <mtp/list/List\.hpp>

#include <iostream>

using namespace mtp;

template<typename T>
using to_int = int;

template<typename T>
struct _to_int : TConst<int> {};

int main (int , char** ) {
    using L = List<int, double*, char&>;
    using __ = ShowType<
//        L,
//        at<L, 0>,
//        at<L, 2>, 
//        at<push_back<L, long>, 3>, 
//        at<push_back<int, long>, 3>, 
//        at<L, 5>, 
        clear<void>,
//        clear<L>,
//        concat<List<int, int&>, List<double&&, double const>>,
//        range<L, 1, 2>,
//        insert_back<L, int&&>,
//        insert_front<L, int&&>,
//        insert<L, int&&, 12>,
        insert_range<L, L, 1>,
        transform<transform<L, _to_int>, type_of>,

        void
    >;

    std::cout << size<L>::value << std::endl; 
    std::cout << empty<L>::value << std::endl; 
    std::cout << empty<List<>>::value << std::endl; 
    

    return 0;
}