#include <iostream>

#include <atomic> // for 'std::atomic'
#include <csignal> // for signal handling structs and routines
#include <map>
#include <thread> // for 'std::this_thread::sleep_for()'

std::atomic<bool> keepAlive = true;
std::map<uint8_t, std::string> signals;

void signalInterruptHandlerCallback(int32_t signalNumber) {
    std::cout << "\nInterrupted by signal number: " << signalNumber << " = " << signals.at(signalNumber) << std::endl;
    keepAlive = false;
    std::cout << "Stopping infinite loop...: " << "keepAlive = " << keepAlive << std::endl;
}

int main() {
    std::cout << "Setting up signal handler..." << std::endl;
    struct sigaction sigIntHandler;
//    memset(&sigIntHandler, 0, sizeof(sigIntHandler) ); // '#include <cstring>' to support 'memset' function
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
