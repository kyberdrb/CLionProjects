#include <chrono>
#include <iostream>
#include <memory>
#include <ranges>
#include <thread>
#include <vector>

/// Observer = EventReceiver = Listener = Subscriber
///   The observer of events
///   Receives events from the Subject; listens to events from the Subject and acts upon them
class Observer {
public:
    explicit Observer(std::string name) :
        _name(std::move(name))
    {}

    [[nodiscard]]
    const std::string& getName() const {
        return this->_name;
    }

    void update(std::string_view value) {
        std::cout << "Observer '" << this->_name << "': update request received with value '" << value << "'" << std::endl;
    }

private:
    std::string _name;
};

/// Subject = EventEmitter = Publisher
///   The creator of events - creates events and sends them to the observers
class Subject {
public:
    Subject() = default;

    // register/add/attach an Observer/Subscriber/Listener/EventReceiver
    void registerObserver(std::unique_ptr<Observer> observer) {
        this->observers.emplace_back(std::move(observer));
        std::cout << "Subject: Observer registered with name: '" << this->observers.back()->getName() << "'" << std::endl;
    }

    void changeInternalState(std::string newState) {
        std::stringstream strStream;
        strStream << "Subject: changing state";

        if (this->_state) {
            strStream << " from '" << *this->_state << "'";
        }

        this->_state = std::move(newState);

        strStream << " to '" << *this->_state << "'";
        std::cout << strStream.str() << std::endl;

        this->notifyObservers(*this->_state);
    }

    void removeObserver(std::string observersName) {
#if __cplusplus >= 202002L
        std::erase_if(this->observers,
            [&observersName](const auto& observerForDeletion) {
                return observersName == observerForDeletion->getName();
            }
        );
        constexpr auto deletionTypeDescription = "(via C++20 'erase_if')";
#else
         // clang-tidy: 'std::erase_if' can be used
         this->observers.erase(std::remove_if(this->observers.begin(), this->observers.end(),
         [&observersName](const auto& observerForDeletion) -> bool {
                     return observerForDeletion->getName() == observersName;
                 }
             ),
             this->observers.end()
         );
        constexpr auto deletionTypeDescription = "(via the vector's 'erase' function)";
#endif
        std::cout << "Observer '" << observersName << "' unregistered " << deletionTypeDescription << std::endl;
    }

private:
    std::vector<std::unique_ptr<Observer>> observers;
    std::optional<std::string> _state;

    void notifyObservers(std::string_view newState) {
        std::cout << "Subject: sending/pushing update notification to all registered observers/listeners/subscribers" << std::endl;
        for (auto& observer : this->observers) {
            observer->update(newState);
        }
        std::cout << "Subject: all observers notified; The Subject doesn't care how the value is processed by the observers" << std::endl;
    }
};

int main() {
    auto eventReceiverForGUI = std::make_unique<Observer>("GUI");
    auto eventReceiverForDB = std::make_unique<Observer>("Database");
    auto eventReceiverForHW = std::make_unique<Observer>("Pluggable hardware with LED");

    auto eventEmitter = std::make_unique<Subject>();
    eventEmitter->registerObserver(std::move(eventReceiverForGUI));
    eventEmitter->registerObserver(std::move(eventReceiverForDB));
    eventEmitter->registerObserver(std::move(eventReceiverForHW));

    std::cout << '\n';

    eventEmitter->changeInternalState("<new value measured/captured/computed>");

    std::thread eventEmitterThreadForChangingStates([&eventEmitter]() {
        for (auto iterationNumber : std::views::iota(0, 2)) {
            std::cout << '\n';
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            eventEmitter->changeInternalState("new value measured/captured/computed>: " + std::to_string(iterationNumber));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    });
    eventEmitterThreadForChangingStates.join();
    std::cout << '\n';

    eventEmitter->removeObserver("GUI");
    std::cout << '\n';

    eventEmitter->changeInternalState("<another value measured/captured/computed> - btw one of the observers had been removed");

    return 0;
}
