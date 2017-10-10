#include <mtp/Config.h>
#include <mtp/Utils.h>

#include <mtp/random/Seed.h>
#include <mtp/random/Random.h>

#include <mtp/list/List.h>

#include <iostream>

using namespace mtp;
int main (int argc, char** argv) {

    using L = List<int, double*, char&>;
    //ShowType<L> s;

    std::cout << size<L>::value << std::endl; 
    std::cout << empty<L>::value << std::endl; 
    std::cout << empty<List<>>::value << std::endl; 
    

    return 0;
}