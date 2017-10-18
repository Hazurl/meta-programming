#include <mtp/Config.h>
#include <mtp/Utils.h>

#include <mtp/random/Seed.h>
#include <mtp/random/Random.h>

#include <mtp/list/List.h>

#include <iostream>

int main (int , char** ) {
    using namespace mtp;

    using L = List<int, double*, char&>;
    using A0 = at<L, 0>;
    using A1 = at<L, 1>;
    using A2 = at<L, 2>;
    using A3 = at<push<L, long>, 3>;
    using A4 = at<push<int, long>, 3>;
    using A5 = at<L, 5>;
    ShowType<A0, A1, A2, A3> s;

    std::cout << size<L>::value << std::endl; 
    std::cout << empty<L>::value << std::endl; 
    std::cout << empty<List<>>::value << std::endl; 
    std::cout << empty<ListEmpty>::value << std::endl; 
    

    return 0;
}