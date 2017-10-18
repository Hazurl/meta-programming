#include <mtp/Config.h>
#include <mtp/Utils.h>

#include <mtp/random/Seed.h>
#include <mtp/random/Random.h>

#include <mtp/list/List.h>

#include <iostream>

int main (int , char** ) {
    using namespace mtp;

    using L = List<int, double*, char&>;
    using __ = ShowType<
//        L,
//        at<L, 0>,
//        at<L, 2>, 
//        at<push_back<L, long>, 3>, 
//        at<push_back<int, long>, 3>, 
//        at<L, 5>, 
//        clear<void>,
//        clear<L>,
//        concat<List<int, int&>, List<double&&, double const>>,
//        range<L, 1, 2>,
//        insert_back<L, int&&>,
//        insert_front<L, int&&>,
//        insert<L, int&&, 12>,
        insert_range<L, L, 1>,

        void
    >;

    std::cout << size<L>::value << std::endl; 
    std::cout << empty<L>::value << std::endl; 
    std::cout << empty<List<>>::value << std::endl; 
    

    return 0;
}