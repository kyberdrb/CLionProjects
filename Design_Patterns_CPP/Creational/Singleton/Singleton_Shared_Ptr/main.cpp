#include <iostream>
#include <thread>
#include "Singleton.h"

class SingletonUser {
public:
    void useSingleton() {
        std::cout << "Hello from thread. Waiting for destruction..." << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(5));
    }
};

int main() {
    Singleton& singleton = Singleton::getInstance();
    std::cout << singleton.use() << std::endl;

    std::unique_ptr<SingletonUser> singletonUser(new SingletonUser);
    std::thread singletonTesterThread(&SingletonUser::useSingleton, singletonUser.get());
    singletonTesterThread.join();

    return 0;
}
