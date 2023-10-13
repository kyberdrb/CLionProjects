//
// Created by admin on 12. 10. 2023.
//

#pragma once

#include <cstdint>
#include <iosfwd>
#include <memory>
#include <ostream>

class Device {
public:
    Device(uint32_t id) :
        _id(id)
    {}

//    bool operator==(const Device& device) {
//        return this->_id == device._id;
//    }

    // to make std::find work
    friend bool operator==(const std::unique_ptr<Device>& firstDevice, const Device& otherDevice);

    // to make std::sort work
    friend bool operator<(const std::unique_ptr<Device>& firstDevice, const std::unique_ptr<Device>& otherDevice);

    friend std::ostream& operator<<(std::ostream& out, const Device& device);

private:
    uint32_t _id;
};
