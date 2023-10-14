//
// Created by laptop on 10/14/23.
//

#pragma once

#include <cstdint>
#include <memory>
#include <iosfwd>

class Device {
public:
    explicit Device(uint32_t id) :
            _id(id)
    {}

    // Doesn't work - set::find() doesn't find anything
//    bool operator<(const Device& anotherDevice) {
//        return this->_id < anotherDevice._id;
//    }

    // Doesn't work - set::find() doesn't find anything
//    bool operator<(const std::unique_ptr<Device>& anotherDevice) {
//        return this->_id < anotherDevice->_id;
//    }

    friend bool operator<(const std::unique_ptr<Device>& oneDevice, const std::unique_ptr<Device>& anotherDevice) {
        return oneDevice->_id < anotherDevice->_id;
    }

    friend std::ostream& operator<<(std::ostream& out, const Device& device);

private:
    uint32_t _id;
};
