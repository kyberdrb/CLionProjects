#include "Singleton.h"

#include <iostream>
#include <thread>

void threadJob(uint32_t delay){
    for (int i = 0; i < 100; ++i) {
//    while (true) {
        // Following code emulates slow initialization.
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        Singleton& singleton = Singleton::getInstance();
        singleton.doSomething();
    }
}

int main() {
    // Access the Singleton instance
    Singleton& singleton = Singleton::getInstance("S1");

    // Use the Singleton
    singleton.doSomething();

    Singleton& singleton1 = Singleton::getInstance("S2");
    Singleton& singleton2 = Singleton::getInstance("S3");

    singleton1.doSomething();
    std::cout << singleton1.getValue() << "\n";
    singleton2.doSomething();
    std::cout << singleton2.getValue() << "\n";

    std::cout << '\n';
    std::cout <<"If you see the same value, then singleton was reused (yay!)\n" <<
              "If you see different values, then 2 singletons were created (booo!!)\n" <<
              "RESULT:\n";
//    std::thread t1(threadJob, 1000);
//    std::thread t2(ThreadBar, 1000);
//    std::thread t1(threadJob, 1000);
//    std::thread t2(ThreadBar, 1000);
    std::thread t1(threadJob, 10);
    std::thread t2(threadJob, 10);
    std::thread t3(threadJob, 10);
    std::thread t4(threadJob, 10);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // The following would not compile due to deleted copy/move constructors and assignment operators
    // Singleton singleton3 = singleton1;
    // Singleton singleton4 = std::move(singleton1);

    return 0;
}