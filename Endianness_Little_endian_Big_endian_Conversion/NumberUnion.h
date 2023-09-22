//
// Created by admin on 22. 9. 2023.
//

#pragma once

#include <cstdint>

union NumberUnion {
    uint32_t raw;
    uint8_t array[4];
};
