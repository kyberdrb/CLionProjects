//
// Created by laptop on 7/22/19.
//

#ifndef TEMPLATES_BOTTLE_H
#define TEMPLATES_BOTTLE_H


#include <stdint-gcc.h>
#include <ostream>

class Bottle {
private:
    uint_fast32_t volume;

public:
    Bottle(uint_fast32_t volume) : volume(volume) {}

    friend std::ostream& operator<<(std::ostream& out, const Bottle& bottle) {
        return out << bottle.volume << std::flush;
    }

};


#endif //TEMPLATES_BOTTLE_H
