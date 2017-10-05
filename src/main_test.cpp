#include <mtp/config.h>
#include <mtp/random/Seed.h>

int main (int argc, char** argv) {
    using namespace MTP_NS;

    std::cout << Seed::get() << std::endl;

    return 0;
}