#include <iostream>

#include <chrono>
#include <thread>

void firstWorkingExamplesOfDelay();
void sleep_ms(uint32_t delayInMilliseconds);

#include <sys/ioctl.h>
void animationWithDynamicLineCleanup();

#include "ncurses.h"
void firstWorkingExampleInNCurses();

void animationInNCurses();
WINDOW* mainwin;
#include <csignal>
void cleanUpNCurses(int32_t signal) {
    if (mainwin != nullptr) {
        delwin(mainwin);
        endwin();
        refresh();
        std::cout << "Memory allocated for NCurses cleaned up" << '\n';
    }
    std::cout << "Interrupted by SIGINT: " << "Caught signal " << signal << std::endl;
    exit(1);
}

#include "AnimationInNCurses.h"
void animationInNCursesEncapsulatedInClass();

int main() {
    //firstWorkingExamplesOfDelay();
    //animationWithDynamicLineCleanup();
    //firstWorkingExampleInNCurses();
    //animationInNCurses();
    animationInNCursesEncapsulatedInClass();

    return 0;
}

void firstWorkingExamplesOfDelay() {
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;

    begin = std::chrono::steady_clock::now();
    end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ns]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    std::cout << "\n---\n\n";

    std::cout << "Hello waiter" << std::endl;
    std::chrono::milliseconds dura( 250 );

    auto start = std::chrono::system_clock::now();
    std::this_thread::sleep_for( dura );
    auto finish = std::chrono::system_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    std::cout << "Waited for " << elapsed.count() << " ms" << std::endl;

    start = std::chrono::system_clock::now();
    std::this_thread::sleep_for( dura );
    finish = std::chrono::system_clock::now();

    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    std::cout << "Waited for " << elapsed.count() << " ms" << std::endl;

    start = std::chrono::system_clock::now();
    std::this_thread::sleep_for( dura );
    finish = std::chrono::system_clock::now();

    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    std::cout << "Waited for " << elapsed.count() << " ms" << std::endl;

    std::cout << "\n---\n\n";

    using namespace std::chrono_literals;

    std::cout << "\r|" << std::flush;
    start = std::chrono::system_clock::now();
    std::this_thread::sleep_for( dura );
    finish = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);

    std::cout << "\r/" << std::flush;
    start = std::chrono::system_clock::now();
    std::this_thread::sleep_for( dura );
    finish = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);

    std::cout << "\r-" << std::flush;
    start = std::chrono::system_clock::now();
    std::this_thread::sleep_for( dura );
    finish = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);

    std::cout << "\r\\" << std::flush;
    start = std::chrono::system_clock::now();
    std::this_thread::sleep_for( dura );
    finish = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);

    auto start_steady = std::chrono::steady_clock::now();
    auto finish_steady = std::chrono::steady_clock::now();

    while (true) {
        std::cout << "\r|" << std::flush;
        start = std::chrono::system_clock::now();
//        start = std::chrono::high_resolution_clock::now();
//        start_steady = std::chrono::steady_clock::now();
        std::this_thread::sleep_for(500ms);
        finish = std::chrono::system_clock::now();
//        finish = std::chrono::high_resolution_clock::now();
//        finish_steady = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
//        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish_steady - start_steady);

        std::cout << "\r/" << std::flush;
        start = std::chrono::system_clock::now();
//        start = std::chrono::high_resolution_clock::now();
//        start_steady = std::chrono::steady_clock::now();
        std::this_thread::sleep_for(1500ms);
        finish = std::chrono::system_clock::now();
//        finish = std::chrono::high_resolution_clock::now();
//        finish_steady = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
//        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish_steady - start_steady);

        std::cout << "\r-" << std::flush;
        start = std::chrono::system_clock::now();
//        start = std::chrono::high_resolution_clock::now();
//        start_steady = std::chrono::steady_clock::now();
        std::this_thread::sleep_for(500ms);
        finish = std::chrono::system_clock::now();
//        finish = std::chrono::high_resolution_clock::now();
//        finish_steady = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
//        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish_steady - start_steady);

        std::cout << "\r\\" << std::flush;
        start = std::chrono::system_clock::now();
//        start = std::chrono::high_resolution_clock::now();
//        start_steady = std::chrono::steady_clock::now();
        std::this_thread::sleep_for(1500ms);
        finish = std::chrono::system_clock::now();
//        finish = std::chrono::high_resolution_clock::now();
//        finish_steady = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
//        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish_steady - start_steady);
    }
}

void sleep_ms(uint32_t delayInMilliseconds) {
    //std::cout << "\r|" << std::flush;
    //start = std::chrono::system_clock::now();
//        start = std::chrono::high_resolution_clock::now();
//        start_steady = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(delayInMilliseconds));
    //finish = std::chrono::system_clock::now();
//        finish = std::chrono::high_resolution_clock::now();
//        finish_steady = std::chrono::steady_clock::now();
    //elapsed = std::chrono::duration_cast<std::chrono::delayInMilliseconds>(finish - start);
//        elapsed = std::chrono::duration_cast<std::chrono::delayInMilliseconds>(finish_steady - start_steady);
}

void animationWithDynamicLineCleanup() {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);

    while (true) {
        uint32_t delayInMilliseconds {500};

        ioctl(0, TIOCGWINSZ, &w);
        std::string emptiness(w.ws_col - 1, ' ');

        //std::cout << w.ws_col << std::endl;
        //sleep_ms(100);

//        std::cout << "\r|" << emptiness << std::flush;
//        sleep_ms(delayInMilliseconds);
//        std::cout << "\r/" << emptiness << std::flush;
//        sleep_ms(delayInMilliseconds);
//        std::cout << "\r-" << emptiness << std::flush;
//        sleep_ms(delayInMilliseconds);
//        std::cout << "\r\\" << emptiness << std::flush;
//        sleep_ms(delayInMilliseconds);

        ioctl(0, TIOCGWINSZ, &w);
        std::string emptiness_0(w.ws_col - 1, ' ');
        std::cout << "\r|" << emptiness_0 << std::flush;
        sleep_ms(delayInMilliseconds);

        ioctl(0, TIOCGWINSZ, &w);
        std::string emptiness_1(w.ws_col - 1, ' ');
        std::cout << "\r/" << emptiness_1 << std::flush;
        sleep_ms(delayInMilliseconds);

        ioctl(0, TIOCGWINSZ, &w);
        std::string emptiness_2(w.ws_col - 1, ' ');
        std::cout << "\r-" << emptiness_2 << std::flush;
        sleep_ms(delayInMilliseconds);

        ioctl(0, TIOCGWINSZ, &w);
        std::string emptiness_3(w.ws_col - 1, ' ');
        std::cout << "\r\\" << emptiness_3 << std::flush;
        sleep_ms(delayInMilliseconds);
    }
}

void firstWorkingExampleInNCurses() {
    initscr();
    addstr("Goodbye, cruel C programming!");
    refresh();
    sleep_ms(3000);
    endwin();


    clear();


    WINDOW * mainwin;


    /*  Initialize ncurses  */

    if ( (mainwin = initscr()) == NULL ) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }


    /*  Display "Hello, world!" in the centre of the
	screen, call refresh() to show our changes, and
	sleep() for a few seconds to get the full screen effect  */

    mvaddstr(13, 33, "Hello, world!");
    refresh();
    sleep_ms(3000);


    /*  Clean up after ourselves  */

    delwin(mainwin);
    endwin();
    refresh();
}

void animationInNCurses() {
    // Deallocate memory for NCurses on Ctrl + C keypress - handle SIGINT signal
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = cleanUpNCurses;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    //WINDOW* ncursesMainWin;

    /*  Initialize ncurses  */
    mainwin = initscr();
    if ( mainwin == NULL ) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }

    /*  Display "Hello, world!" in the centre of the
	screen, call refresh() to show our changes, and
	sleep() for a few seconds to get the full screen effect  */

    uint32_t delayInMilliseconds {50};

//    mvaddch(0, 0, '|');
//    refresh();
//    sleep_ms(delayInMilliseconds);
//
//    mvaddch(0, 0, '/');
//    refresh();
//    sleep_ms(delayInMilliseconds);
//
//    mvaddch(0, 0, '-');
//    refresh();
//    sleep_ms(delayInMilliseconds);
//
//    mvaddch(0, 0, '\\');
//    refresh();
//    sleep_ms(delayInMilliseconds);
//
//    /*  Clean up after ourselves  */
//    delwin(ncursesMainWin);
//    endwin();
//    refresh();

    while (true) {
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
    }
}

void animationInNCursesEncapsulatedInClass() {
    AnimationInNCurses animationInNCurses;
    animationInNCurses.start();
}
