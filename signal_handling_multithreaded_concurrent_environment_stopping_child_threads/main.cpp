//#include "JoinableThreadWrapper.h"

#include <iostream>

#include <atomic> // for 'std::atomic'
//#include <functional> // for 'std::bind'
#include <csignal> // for signal handling structs and routines
#include <cstring> // for 'memset'
#include <map>
#include <sstream>
#include <thread> // for 'std::this_thread::sleep_for()'
#include <vector>

//std::vector<std::unique_ptr<JoinableThreadWrapper>> threadPool;

//static std::mutex dataProcessingMutex;
////void threadDataProcessingFunction(int32_t threadPosition, int32_t data) {
//void threadDataProcessingFunction(int32_t data) {
//    std::lock_guard<std::mutex> criticalSectionGuard(dataProcessingMutex);
////    auto _threadID = threadPool.at(threadPosition).get_id();
////    std::cout << "threadPosition = " << threadPosition << "; _threadID = " << _threadID << "; data = " << data << std::endl;
//    std::cout << "data = " << data << std::endl;
//}

std::mutex terminalMutex;

template <typename T>
void printMessageWithNewlineSynchronously(const T& message, bool skipNewline = false, bool debugNewline = true) {
    std::lock_guard<std::mutex> lockGuard(terminalMutex);

    if (skipNewline) {
        std::cout << message;
        return;
    }

    if (debugNewline) {
        std::cout << std::endl;
    } else {
        std::cout << '\n';
    }

    std::cout << message;
}

//template <typename T>
//void printMessageWithoutNewline(const T& message) {
//    std::lock_guard<std::mutex> lockGuard(terminalMutex);
//    std::cout << message << std::flush;
//    //std::cout << message;
//}

/*
static std::mutex terminalMutex;
void printToTerminal(const std::string& message) {
    std::lock_guard<std::mutex> criticalSectionGuard(terminalMutex);
    std::cout << message << std::endl;
}
*/

std::atomic<bool> keepAlive = true;
std::map<int32_t, std::string> signals;

void signalInterruptHandlerCallback(const int32_t signalNumber) {
    std::stringstream message;
    message << "\nInterrupted by signal number: " << signalNumber << " = " << keepAlive;

    try {
        message << signals.at(signalNumber) << std::endl;
    }
    catch (const std::out_of_range&) {
        message << "unnamed signal number";
    }

    keepAlive = false;
    message << "Stopping infinite loop...: " << "keepAlive = " << keepAlive;
    //std::cout << message.str() << std::endl;
    printMessageWithNewlineSynchronously(message.str() );
}

//int main() {
//    std::cout << "Setting up signal handler..." << std::endl;
//    struct sigaction sigIntHandler = {nullptr};
//
//    // Initialize the 'sigaction' struct to its default values to prevent undefined behavior
//    //  with 'memset', because it's a C-struct without a constructor, which would initialize the struct's fields.
//    //  'memset' overwrites the struct's values to '0's
//    //  Note: signal handler catches interrupt messages properly even without initializing the struct for it
//    memset(&sigIntHandler, 0, sizeof(sigIntHandler) );
//
//    sigIntHandler.sa_handler = signalInterruptHandlerCallback;
//    sigemptyset(&sigIntHandler.sa_mask);
//    sigIntHandler.sa_flags = 0;
//    sigaction(SIGINT, &sigIntHandler, nullptr);  // 'Ctrl + C' OR 'kill -s 2 <program_PID>'
//    sigaction(SIGHUP, &sigIntHandler, nullptr);  // 'kill -s 1 <program_PID>'
//    sigaction(SIGTERM, &sigIntHandler, nullptr); // 'Ctrl + F2' from CLion: Stop <program_name> OR stop from terminal via 'kill -s 15 <program_PID>'
//    sigaction(SIGQUIT, &sigIntHandler, nullptr); // stop from terminal via 'kill -s 3 <program_PID>'
//
//    signals.emplace(SIGINT, "SIGINT");
//    signals.emplace(SIGHUP, "SIGHUP");
//    signals.emplace(SIGQUIT, "SIGQUIT");
//    signals.emplace(SIGTERM, "SIGTERM");
//
//    // TODO spawn joinable threads:
//    //  - each joinable thread spawns one detached thread for each connection to process data
//    std::cout << "Spawning threads..." << std::endl;
//    threadPool.emplace_back(std::make_unique<JoinableThreadWrapper>(111));
//    threadPool.emplace_back(std::make_unique<JoinableThreadWrapper>(222));
//    threadPool.emplace_back(std::make_unique<JoinableThreadWrapper>(333));
//
//    for (const auto& joinableThreadWrapper : threadPool) {
//        joinableThreadWrapper->start();
//    }
//
//    std::cout << "Starting infinite idle loop...: " << "keepAlive = " << keepAlive << std::endl;
//
//    std::cout << "Main thread idling :) " << std::flush;
//    const std::chrono::milliseconds duration(500);
//    while (keepAlive) {
//        std::this_thread::sleep_for(duration);
//        std::cout << "." << std::flush;
//    }
//
//    std::cout << "Broken out from the loop. Leaving 'main()'..." << std::endl;
//    return 0;
//}

#include <iostream>
#include <thread>

enum class ThreadType {
    JOINABLE,
    DETACHED
};

class ThreadWrapper {
public:
    // Constructor
    ThreadWrapper(int32_t data, ThreadType threadType = ThreadType::JOINABLE) :
        _thread(),
        _isRunning(false),
        _data(data),
        _threadType(threadType)
    {}

    // Destructor
    ~ThreadWrapper() {
        const auto threadID = this->_threadID;
//        std::cout << "ThreadWrapper.DESTRUCTOR: Thread [" << threadID << "] [" << this->_data << "]: terminating..." << std::endl;
        {
            std::stringstream message;
            message << "ThreadWrapper.DESTRUCTOR: Thread [" << threadID << "] [" << this->_data << "]: terminating...";
            printMessageWithNewlineSynchronously(message.str());
        }
        if (_isRunning) {
            join();
        }
//        std::cout << "ThreadWrapper.DESTRUCTOR: Thread [" << threadID << "] [" << this->_data << "]: terminated." << std::endl;
        {
            std::stringstream message;
            message << "ThreadWrapper.DESTRUCTOR: Thread [" << threadID << "] [" << this->_data << "]: terminated.";
            printMessageWithNewlineSynchronously(message.str());
        }
    }

    // Start the thread
    template<typename Function, typename... Args>
    void start(Function&& func, Args&&... args) {
        if ( !(this->_isRunning ) ) {
            std::stringstream message;
            this->_thread = std::thread(std::forward<Function>(func), std::forward<Args>(args)...);
            this->_threadID = this->_thread.get_id();
            this->_isRunning = true;

            message << "ThreadWrapper.start: Thread [" << this->_threadID << "] " << "is running in ";
            switch (this->_threadType) {
                case ThreadType::JOINABLE:
                    message << "[joinable]";
                    break;
                case ThreadType::DETACHED:
                    this->_thread.detach(); // after detaching the thread, the thread id will no longer be available
                    message << "[detached]";
                    break;
                default:
                    message << "[unknown]";
                    break;
            }
            message << " mode.";
            printMessageWithNewlineSynchronously(message.str());
        }
    }

    void startInternalFunction(int32_t threadData) {
        this->start(&ThreadWrapper::internalThreadFunction, this, threadData);
    }

    void internalThreadFunction(int32_t threadData) {
        while (keepAlive) {
            std::stringstream message;
            message << "Thread [" << this->_threadID << "] with member data [" << this->_data << "] and thread data ["
                      << threadData << "] is running.";
            printMessageWithNewlineSynchronously(message.str());
            std::this_thread::sleep_for(std::chrono::milliseconds(1000) );
        }
        std::stringstream message;
        message << "ThreadWrapper.internalThreadFunction: Thread [" << this->_threadID << "] [" << this->_data << "]: terminated.";
        printMessageWithNewlineSynchronously(message.str());
    }

public:
    void startInternalFunctionWithInternalStateOnlyThroughGenericFunction() {
        this->start(&ThreadWrapper::internalThreadFunctionInternalStateOnly, this);
    }

private:
    void internalThreadFunctionInternalStateOnly() const {
        while (keepAlive) {
            std::stringstream message;
            message << "Thread [" << this->_threadID << "] with member data [" << this->_data << "] is running.";
            printMessageWithNewlineSynchronously(message.str());
            std::this_thread::sleep_for(std::chrono::milliseconds(1000) );
        }
        std::stringstream message;
        message << "ThreadWrapper.internalThreadFunctionInternalStateOnly: Thread [" << this->_threadID << " [" << this->_data << "] terminated.";
        printMessageWithNewlineSynchronously(message.str());
    }

public:
    void startInternalFunctionWithInternalStateOnlyThroughSelfContainedFunction() {
        if ( !(this->_isRunning ) ) {
            this->_thread = std::thread(&ThreadWrapper::internalThreadFunctionInternalStateOnly, this);
            this->_threadID = this->_thread.get_id();
            this->_isRunning = true;

            std::stringstream message;
            message << "ThreadWrapper.startInternalFunctionWithInternalStateOnlyThroughSelfContainedFunction: Thread [" << this->_threadID << "] " << "is running in ";
            switch (this->_threadType) {
                case ThreadType::JOINABLE:
                    message << "[joinable]";
                    break;
                case ThreadType::DETACHED:
                    this->_thread.detach(); // after detaching the thread, the thread id will no longer be available
                    message << "[detached]";
                    break;
                default:
                    message << "[unknown]";
                    break;
            }
            message << " mode." << std::endl;
            printMessageWithNewlineSynchronously(message.str());
        }
    }

    // Join the thread
    void join() {
        if (_thread.joinable()) {
            _thread.join();
            _isRunning = false;
        }
    }

    int32_t getData() const {
        return this->_data;
    }

    std::thread::id getThreadID() const {
        return this->_threadID;
    }

    friend std::ostream& operator<<(std::ostream& out, const ThreadWrapper& threadWrapper);

private:
    std::thread _thread;
    bool _isRunning;
    int32_t _data;
    ThreadType _threadType;

    std::thread::id _threadID;
};

std::ostream& operator<<(std::ostream& out, const ThreadWrapper& threadWrapper) {
    out << threadWrapper.getData();
    return out;
}

// Example thread function
void threadFunction(int32_t threadData, const ThreadWrapper& threadWrapper) {
    while (keepAlive) {
        {
            std::stringstream message;
            message << "::threadFunction: Thread [" << threadWrapper.getThreadID() << "] with member data [" << threadWrapper
                << "] and thread data [" << threadData << "] is running.";
            printMessageWithNewlineSynchronously(message.str());
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000) );
    }

    {
        std::stringstream message;
        message << "threadFunction: Thread [" << threadWrapper.getThreadID() << "] [" << threadWrapper.getData() << "] terminated.";
        printMessageWithNewlineSynchronously(message.str());
    }
}

int main() {
    printMessageWithNewlineSynchronously("main: Setting up signal handler...");
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

    ThreadWrapper joinableThreadWrapper(111);

    // Start the thread
    joinableThreadWrapper.start(threadFunction, 1, std::cref(joinableThreadWrapper));

    ThreadWrapper anotherJoinableThreadWrapper(222);
    anotherJoinableThreadWrapper.startInternalFunction(2);

    ThreadWrapper detachedThreadWrapper(333, ThreadType::DETACHED);
    detachedThreadWrapper.startInternalFunction(3);

    ThreadWrapper yetAnotherJoinableThreadWrapper(444);
    yetAnotherJoinableThreadWrapper.start(&ThreadWrapper::internalThreadFunction, &yetAnotherJoinableThreadWrapper, 4);

    ThreadWrapper joinableThreadWrapperWithInternalStateOnly(555);
    joinableThreadWrapperWithInternalStateOnly.startInternalFunctionWithInternalStateOnlyThroughGenericFunction();

    ThreadWrapper anotherJoinableThreadWrapperWithInternalStateOnly(666);
    anotherJoinableThreadWrapperWithInternalStateOnly.startInternalFunctionWithInternalStateOnlyThroughSelfContainedFunction();

    std::vector<std::unique_ptr<ThreadWrapper>> joinableThreadPool;
    joinableThreadPool.emplace_back(std::make_unique<ThreadWrapper>(777) );
    joinableThreadPool.emplace_back(std::make_unique<ThreadWrapper>(888) );
    joinableThreadPool.emplace_back(std::make_unique<ThreadWrapper>(999) );

    for (const auto& thread : joinableThreadPool) {
        thread->startInternalFunctionWithInternalStateOnlyThroughSelfContainedFunction();
    }

    std::vector<std::unique_ptr<ThreadWrapper>> detachedThreadPool;
    detachedThreadPool.emplace_back(std::make_unique<ThreadWrapper>(1001) );
    detachedThreadPool.emplace_back(std::make_unique<ThreadWrapper>(1002) );

    for (const auto& thread : detachedThreadPool) {
        thread->startInternalFunctionWithInternalStateOnlyThroughSelfContainedFunction();
    }

    {
        std::stringstream message;
        message << "main: Starting infinite idle loop...: " << "keepAlive = " << keepAlive;
        printMessageWithNewlineSynchronously(message.str());
    }

    printMessageWithNewlineSynchronously("main: Main thread idling :)");
    const std::chrono::milliseconds duration(500);
    // Waiting for the thread to finish
    while (keepAlive) {
        // Do something else while waiting
        std::this_thread::sleep_for(duration);
//        std::cout << "=" << std::flush;
        printMessageWithNewlineSynchronously('=', true);
    }

    {
        std::stringstream message;
        message << "main: Main thread has finished.";
        //std::cout << message.str() << std::endl;
        printMessageWithNewlineSynchronously(message.str());
    }

    return 0;
}
