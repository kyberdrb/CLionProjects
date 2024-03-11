#include <iostream>

#include <atomic> // for 'std::atomic'
#include <csignal> // for signal handling structs and routines
#include <cstring> // for 'memset'
#include <map>
#include <thread> // for 'std::this_thread::sleep_for()'

std::atomic<bool> keepAlive = true;
std::map<int32_t, std::string> signals;

void signalInterruptHandlerCallback(const int32_t signalNumber) {
	std::cout << "\nInterrupted by signal number: " << signalNumber << " = ";

    try {
        std::cout << signals.at(signalNumber);
    }
    catch (const std::out_of_range&) {
        std::cout << "unnamed signal number";
    }
    std::cout << std::endl;

    keepAlive = false;
    std::cout << "Stopping infinite loop...: " << "keepAlive = " << keepAlive << std::endl;
}

int main() {
    std::cout << "Setting up signal handler..." << std::endl;
    struct sigaction sigIntHandler = {nullptr};

    // Initialize the 'sigaction' struct to its default values to prevent undefined behavior
    //  with 'memset', because it's a C-struct without a constructor, which would initialize the struct's fields.
    //  'memset' overwrites the struct's values to '0's
    //  Note: signal handler catches interrupt messages properly even without initializing the struct for it
    memset(&sigIntHandler, 0, sizeof(sigIntHandler) );

    sigIntHandler.sa_handler = signalInterruptHandlerCallback;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, nullptr);  // 'Ctrl + C' OR 'kill -s 2 <program_PID>'
    sigaction(SIGHUP, &sigIntHandler, nullptr);  // 'kill -s 1 <program_PID>'
    sigaction(SIGTERM, &sigIntHandler, nullptr); // 'Ctrl + F2' from CLion: Stop <program_name> OR stop from terminal via 'kill -s 15 <program_PID>'
    sigaction(SIGQUIT, &sigIntHandler, nullptr); // stop from terminal via 'kill -s 3 <program_PID>'

    signals.emplace(SIGINT, "SIGINT");
    signals.emplace(SIGHUP, "SIGHUP");
    signals.emplace(SIGQUIT, "SIGQUIT");
    signals.emplace(SIGTERM, "SIGTERM");

    std::cout << "Starting infinite loop...: " << "keepAlive = " << keepAlive << std::endl;

    const std::chrono::milliseconds duration(500);
    while (keepAlive) {
        std::cout << '.' << std::flush;
        std::this_thread::sleep_for(duration);
    }

    std::cout << "Broken out from the loop. Leaving 'main()'..." << std::endl;
    return 0;
}
