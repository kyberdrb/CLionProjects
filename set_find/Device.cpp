//
// Created by laptop on 10/14/23.
//

#include "Device.h"

#include <iostream>

std::ostream& operator<<(std::ostream& out, const Device& device) {
    out << "D" << device._id;
    return out;
}
