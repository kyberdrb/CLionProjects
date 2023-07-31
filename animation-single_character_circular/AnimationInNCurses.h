//
// Created by laptop on 7/30/23.
//

#pragma once

#include "ncurses.h"

#include <atomic>
#include <map>
#include <string>

class AnimationInNCurses {
public:
    AnimationInNCurses();
    void start();
    ~AnimationInNCurses();

private:
    WINDOW* ncursesMainWin;

    std::map<uint8_t, std::string> signals;

    void sleep_ms(uint32_t delayInMilliseconds);
};

inline std::atomic<uint8_t> signalNumberRequestingQuit(0);    // signal flag

// signal handling function
inline void signalInteruptTrapFunction(int signalNumber)
{
    // Signal handler function.
    // Set the flag and return.
    // Never do real work inside this function.
    // See also: man 7 signal-safety
    signalNumberRequestingQuit.store(signalNumber);
}
