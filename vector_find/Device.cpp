//
// Created by admin on 12. 10. 2023.
//

#include "Device.h"

bool operator==(const std::unique_ptr<Device>& firstDevice, const Device& otherDevice) {
    return firstDevice->_id == otherDevice._id;
}

bool operator<(const std::unique_ptr<Device>& firstDevice, const std::unique_ptr<Device>& otherDevice) {
    return firstDevice->_id < otherDevice->_id;
}

std::ostream& operator<<(std::ostream& out, const Device& device) {
    out << "Device " << device._id;
    return out;
}
