#include "Singleton.h"

#include <iostream>
#include <thread>

void printTextAsynchronously(uint32_t delay){
    for (int i = 0; i < 100; ++i) {
//    while (true) {
        // Following code emulates slow initialization.
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        Singleton& singleton = Singleton::getInstance();
        singleton.printTextAsynchronously();
    }
}

void printTextSynchronously(uint32_t delay){
    for (int i = 0; i < 100; ++i) {
//    while (true) {
        // Following code emulates slow initialization.
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        Singleton& singleton = Singleton::getInstance();
        singleton.printTextSynchronously();
    }
}

int main() {
    // Access the Singleton instance...
    //  ...without a parameter
    //Singleton& singleton = Singleton::getInstance();

    // ...with a parameter
    Singleton& singleton = Singleton::getInstance("S1");

    // Use the Singleton
    singleton.printTextSynchronously();

    Singleton& singleton1 = Singleton::getInstance("S2");
    Singleton& singleton2 = Singleton::getInstance("S3");

    singleton1.printTextAsynchronously();
    singleton1.printTextSynchronously();
    std::cout << singleton1.getValue() << "\n";
    singleton2.printTextAsynchronously();
    singleton2.printTextSynchronously();
    std::cout << singleton2.getValue() << "\n";

    std::cout << '\n';
    std::cout <<"If you see the same value, then singleton was reused (yay!)\n" <<
              "If you see different values, then 2 singletons were created (booo!!)\n" <<
              "RESULT:\n";

    std::cout << "\n\nPRINTING TEXT ASYNCHRONOUSLY\n\n";

    std::thread t1(printTextAsynchronously, 10);
    std::thread t2(printTextAsynchronously, 10);
    std::thread t3(printTextAsynchronously, 10);
    std::thread t4(printTextAsynchronously, 10);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "\n\nPRINTING TEXT SYNCHRONOUSLY\n\n";

    std::thread t5(printTextSynchronously, 10);
    std::thread t6(printTextSynchronously, 10);
    std::thread t7(printTextSynchronously, 10);
    std::thread t8(printTextSynchronously, 10);
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    // The following would not compile due to deleted copy/move constructors and assignment operators
    // Singleton singleton3 = singleton1;
    // Singleton singleton4 = std::move(singleton1);

    return 0;
}