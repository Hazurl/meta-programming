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
        L,
        at<L, 0>,
        at<L, 2>, 
        at<push<L, long>, 3>, 
//        at<push<int, long>, 3>, 
//        at<L, 5>, 
//        clear<void>,
        clear<L>,

        void
    >;

    std::cout << size<L>::value << std::endl; 
    std::cout << empty<L>::value << std::endl; 
    std::cout << empty<List<>>::value << std::endl; 
    

    return 0;
}