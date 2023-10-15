#include <iostream>
#include <memory>
#include <sstream>

#include <thread>
#include <mutex>

class Singleton {
public:
    // Function to access the Singleton instance
    static Singleton& getInstance() {
        // Lazy initialization: create the instance on the first access
        if (!instance) {
            std::cout << instance.get() << ": getInstance(): Singleton instance is being created...\n";
            instance = std::make_unique<Singleton>();
            std::cout << instance.get() << ": getInstance(): Singleton instance created." << '\n';;
        }
        return *instance;
    }

    // Function to access the Singleton instance
    static Singleton& getInstance(std::string value) {
        // Lazy initialization: create the instance on the first access
        if (!instance) {
            struct SingletonImpl : public Singleton {
                SingletonImpl(std::string value) : Singleton(std::move(value)) {}
                // no need to declare the destructor of base class Singleton as virtual,
                //  or overriding it here in the derived class,
                //  because derived class has no intrinsic state or behavior
            };
            std::cout << instance.get() << ": getInstance(): Singleton instance is being created...\n";
            instance = std::make_unique<SingletonImpl>(std::move(value));
            std::cout << instance.get() << ": getInstance(): Singleton instance created with value '" << instance->_value << "'" << '\n';
        }
        return *instance;
    }

    // Singleton's public member functions
    void doSomething() {
        // Synchronize access to the std::cout when function 'doSomething' is called from multiple threads
        //  Comment out to see the multithreading bug: overlapping outputs on multithreaded printing on terminal
        std::lock_guard<std::mutex> lock(this->_mutex);

        std::cout << instance.get() << ": Singleton is doing something.\n";
    }

    std::string getValue() const {
        std::stringstream message{};
        message << instance.get() << ": " << this->_value;
        return message.str();
    }

    // Public destructor for std::make_unique
    ~Singleton() {
        std::cout << instance.get() << ": Singleton instance destroyed.\n";
    }

private:
    // Make std::make_unique a friend to access the private default constructor
    friend std::unique_ptr<Singleton> std::make_unique<Singleton>();

    // Private constructor to prevent direct instantiation
    Singleton() :
        _value("<default_value>")
    {
        std::cout << this << ": Constructor: Singleton instance created.\n";
    }

    // Private constructor to prevent direct instantiation
    explicit Singleton(std::string value) :
        _value(std::move(value))
    {
        std::cout << this << ": Constructor: Singleton instance created with value '" << this->_value << "'\n";
    }

    // If we declare the destructor as private, we get an error
    //   error: ‘Singleton::~Singleton()’ is private within this context
    //  because std::make_unique needs public access to the destructor
//    ~Singleton() {
//        std::cout << "Singleton instance destroyed." << std::endl;
//    }

    // Private copy and move constructors to prevent cloning and moving
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;

    // Private assignment operators to prevent copying and moving
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    // The unique_ptr to hold the single instance
    static std::unique_ptr<Singleton> instance;

    std::string _value;
    std::mutex _mutex;
};

// Static member variable initialization
std::unique_ptr<Singleton> Singleton::instance = nullptr;

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