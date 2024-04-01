#include <iostream>
#include <thread>

class MyThreadWrapper {
public:
    // Constructor
    MyThreadWrapper() : m_thread(), m_isRunning(false) {}

    // Destructor
    ~MyThreadWrapper() {
        if (m_isRunning) {
            join();
        }
    }

    // Start the thread with a member function of MyThreadWrapper
    template<typename Function, typename... Args>
    void start(Function&& func, Args&&... args) {
        m_thread = std::thread(std::forward<Function>(func), this, std::forward<Args>(args)...);
        m_isRunning = true;
    }

    // Join the thread
    void join() {
        if (m_thread.joinable()) {
            m_thread.join();
            m_isRunning = false;
        }
    }

    // Check if the thread is running
    bool isRunning() const {
        return m_isRunning;
    }

    // Example member function
    void memberFunction(int id) {
        std::cout << "Member function of MyThreadWrapper called with ID: " << id << std::endl;
    }

private:
    std::thread m_thread;
    bool m_isRunning;
};

int main() {
    MyThreadWrapper threadWrapper;

    // Start the thread with the member function of MyThreadWrapper
    threadWrapper.start(&MyThreadWrapper::memberFunction, 1);

    // Wait for the thread to finish
    while (threadWrapper.isRunning()) {
        // Do something else while waiting
    }

    std::cout << "Thread has finished." << std::endl;

    return 0;
}