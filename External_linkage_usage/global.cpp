#include "global.h"

// We need to define the declared global variable either in a custom namespace in a continuation of that namespace...
namespace Global {
    uint32_t clock_rate = 1'000'000;
}

// ... or we can define a global variable in a custom namespace from global namespace like this:
//uint32_t Global::clock_rate = 1'000'000;
