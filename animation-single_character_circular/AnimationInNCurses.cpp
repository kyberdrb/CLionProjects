//
// Created by laptop on 7/30/23.
//

#include "AnimationInNCurses.h"

#include <csignal>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <iostream>
#include <thread>

AnimationInNCurses::AnimationInNCurses() :
        ncursesMainWin(nullptr)
{
//    struct sigaction sigIntHandler;
//    memset(&sigIntHandler, 0, sizeof(sigIntHandler) ); // '#include <cstring>' to support 'memset' function
//    sigIntHandler.sa_handler = signalInteruptTrapFunction;
//    sigfillset(&sigIntHandler.sa_mask);
//    sigaction(SIGINT, &sigIntHandler, NULL);

    struct sigaction sigIntHandler;
//    memset(&sigIntHandler, 0, sizeof(sigIntHandler) ); // '#include <cstring>' to support 'memset' function
    sigIntHandler.sa_handler = signalInteruptTrapFunction;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, nullptr);  // 'Ctrl + C' OR 'kill -s 2 <program_PID>'
    sigaction(SIGHUP, &sigIntHandler, nullptr);  // 'Ctrl + F2' from CLion: Stop <program_name> OR 'kill -s 1 <program_PID>'
    sigaction(SIGTERM, &sigIntHandler, nullptr); // stop from terminal via 'kill -s 15 <program_PID>'
    sigaction(SIGQUIT, &sigIntHandler, nullptr); // stop from terminal via 'kill -s 3 <program_PID>'

    signals.emplace(SIGINT, "SIGINT");
    signals.emplace(SIGHUP, "SIGHUP");
    signals.emplace(SIGQUIT, "SIGQUIT");
    signals.emplace(SIGTERM, "SIGTERM");

    ncursesMainWin = initscr();
    if (ncursesMainWin == NULL ) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }
}

void AnimationInNCurses::start() {
    mvaddstr(1, 0, std::to_string(signalNumberRequestingQuit.load()).c_str() );
    refresh();

    uint32_t delayInMilliseconds {50};

    while (true) {
    //for (int i = 0; i < 8; ++i) {
        mvaddch(0, 0, '|');
        refresh();
        sleep_ms(delayInMilliseconds);

        mvaddch(0, 0, '/');
        refresh();
        sleep_ms(delayInMilliseconds);

        mvaddch(0, 0, '-');
        refresh();
        sleep_ms(delayInMilliseconds);

        mvaddch(0, 0, '\\');
        refresh();
        sleep_ms(delayInMilliseconds);

//        mvaddch(1, 0, signalNumberRequestingQuit.load() + '0');
        mvaddstr(1, 0, std::to_string(signalNumberRequestingQuit.load()).c_str() );
        refresh();

        if( signalNumberRequestingQuit.load() ) {
            mvaddstr(0, 0, "Quit request received. Exiting gracefully...");
            mvaddstr(2, 0, signals.at(signalNumberRequestingQuit).c_str() );
            refresh();
            sleep_ms(3500);
            break;    // exit normally after SIGINT
        }
    }
}

void AnimationInNCurses::sleep_ms(uint32_t delayInMilliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delayInMilliseconds));
}

AnimationInNCurses::~AnimationInNCurses() {
    if (ncursesMainWin != nullptr) {
        delwin(ncursesMainWin);
        endwin();
        refresh();
        std::cout << "AnimationInNCurses::Destructor: Memory allocated for NCurses cleaned up" << '\n';
    }

    std::cout << "Signal number: " << std::to_string(signalNumberRequestingQuit) << '\n';
    std::cout << "Signal name: " << signals.at(signalNumberRequestingQuit) << '\n';
}
