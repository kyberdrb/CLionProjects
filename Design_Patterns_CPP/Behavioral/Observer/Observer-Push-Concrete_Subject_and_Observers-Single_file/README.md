# Observer Design Pattern

## Variant

Push-Observer with Concrete `Subject` and `Observer` classes

## Purpose

Beginner-friendly Observer implementation in single self-contained file.

Observer design pattern is used to model 1-to-N relationship where there is 1 Subject/EventEmitter/Sender/Publisher that sends events and multiple Observers/Listeners/EventReceivers/Subscribers.

It also serves a purpose of decoupling the Sender from its Receivers., which adheres to the Low-Coupling principle and Open-Closed principle.

## Refactoring

(me): Based on what C++ code would you know that it is the time to refactor into an Observer design pattern?

ChatGPT: Refactoring into the **Observer design pattern** becomes appropriate when you recognize a recurring problem involving one-to-many relationships between objects, especially when the following signs are present in your C++ code:

### Key Signs to Refactor into the Observer Pattern:

1. **Manual State Notifications**:
    - You have multiple objects dependent on the state of another object, and you're manually notifying each one whenever the state changes.
    - **Example**:
      ```cpp
      void Subject::changeState() {
          state = newState;
          observer1->update(state); // Manually calling each observer
          observer2->update(state); // Manually repeating notification
      }
      ```
    - **Why refactor**: Adding or removing observers becomes tedious and error-prone. The code is not scalable or flexible as each new observer requires manual updates.

2. **Tight Coupling**:
    - The subject knows about the details of all the observers it notifies. Your `Subject` class may have direct references to specific `Observer` classes.
    - **Example**:
      ```cpp
      class Subject {
          Observer1* obs1;  // Specific observers tightly coupled
          Observer2* obs2;
      public:
          void changeState() {
              // Directly notifying specific observers
              obs1->update(state);
              obs2->update(state);
          }
      };
      ```
    - **Why refactor**: This tightly couples `Subject` and `Observer`, making it difficult to extend or reuse the classes independently. If more observers are added, you must modify the `Subject` class every time.

3. **Frequent Addition/Removal of Observers**:
    - If you frequently add, remove, or change observers in response to different conditions or configurations, but the `Subject` logic becomes too cluttered with all these details.
    - **Example**:
      ```cpp
      void Subject::registerObserver(Observer* obs) {
          observers.push_back(obs);
      }
      
      void Subject::notifyObservers() {
          for (auto* obs : observers) {
              obs->update(state);
          }
      }
      ```
    - **Why refactor**: The above example is moving towards the Observer pattern, but refactoring is needed if the `registerObserver()` and `notifyObservers()` logic grows complex and spread across multiple locations in your codebase.

4. **Multiple Dependent Classes**:
    - If many classes depend on the state or behavior of a single class, and their dependency logic is intertwined with business logic.
    - **Example**:
        - Several parts of your application directly depend on notifications or data from a specific object. If those parts evolve or change independently, managing notifications becomes cumbersome.

5. **Duplication of Notification Code**:
    - If you find yourself writing similar notification code across different classes to notify multiple observers of state changes.
    - **Example**:
      ```cpp
      void SubjectA::notify() {
          for (auto& observer : observers) {
              observer->update(...);
          }
      }
      
      void SubjectB::notify() {
          for (auto& observer : observers) {
              observer->update(...);
          }
      }
      ```
    - **Why refactor**: Duplication suggests that the notification logic should be centralized and abstracted into a pattern like the Observer.

6. **Dynamic Relationships**:
    - If observers may be added or removed dynamically, and managing these changes manually results in complicated and error-prone code.
    - **Example**:
      ```cpp
      subject.registerObserver(observer);
      subject.unregisterObserver(observer);
      ```
    - **Why refactor**: The Observer pattern allows dynamic and flexible relationships between subjects and observers without altering the classes themselves.

### Why Use the Observer Pattern:

1. **Loose Coupling**: The pattern decouples subjects and observers. Subjects don't need to know the details of their observers, making the system more modular.

2. **Open-Closed Principle**: You can add new types of observers without modifying the subject. The system is easier to extend.

3. **Separation of Concerns**: The logic for updating observers is abstracted away from the business logic of the subject.

4. **Event-Driven**: If your system relies on event-driven programming, such as UI updates or messaging systems, the Observer pattern simplifies how events are propagated.

### Example: Refactoring into the Observer Pattern

Before refactoring:

```cpp
class Sensor {
    int temperature;
    Display* display;
    Logger* logger;

public:
    void setTemperature(int newTemp) {
        temperature = newTemp;
        display->update(temperature);  // Manual updates
        logger->log(temperature);      // Manual updates
    }
};
```

After refactoring into the Observer pattern:

```cpp
class Subject {
    std::vector<Observer*> observers;
public:
    void attach(Observer* obs) { observers.push_back(obs); }
    void notify(int newState) {
        for (Observer* obs : observers) {
            obs->update(newState);
        }
    }
};

class Sensor : public Subject {
    int temperature;
public:
    void setTemperature(int newTemp) {
        temperature = newTemp;
        notify(temperature);  // Automatically notifies all observers
    }
};
```

In this refactored example, the `Sensor` no longer has to manually call `update` or `log`. Instead, it simply notifies all observers when its state changes. This simplifies the code, makes it more scalable, and allows for adding or removing observers without modifying the `Sensor` class itself.

## Sources

- https://refactoring.guru/design-patterns/observer
- https://duckduckgo.com/?t=ffab&q=what+is+observer+design+pattern+good+for&ia=web
- https://duckduckgo.com/?t=ffab&q=push+observer+design+pattern&ia=web
- https://duckduckgo.com/?t=ffab&q=pull+observer+design+pattern&ia=web
- https://duckduckgo.com/?t=ffab&q=observer+design+pattern+decouple+sender+receiver&ia=web
- https://sourcemaking.com/design_patterns/observer
- https://duckduckgo.com/?t=ffab&q=observer+uml+class+diagram&iax=images&ia=images
- https://duckduckgo.com/?q=observer+uml+sequence+diagram&t=ffab&iax=images&ia=images&iai=https%3A%2F%2Fperfectjpattern.sourceforge.net%2Fimages%2Fobserver_sequence.png
- https://perfectjpattern.sourceforge.net/dp-observer.html
- https://en.cppreference.com/w/cpp/utility/optional
  - (me) Where would you use `std::optional` as a member variable?

    (ChatGPT) Using `std::optional` as a member variable in a class is beneficial when you want to represent the presence or absence of a value within that class. Here are some common use cases where `std::optional` is particularly useful:
   
     ### 1. **Representing Optional Data**
     - Use `std::optional` to represent data that may or may not be set. This is helpful for fields that are conceptually "optional" and do not require a default value.
       - **Example**: In a `User` class, the `middleName` field may or may not be present:
         ```cpp
         class User {
         public:
             std::string firstName;
             std::optional<std::string> middleName;
             std::string lastName;
         };
         ```
       - This approach avoids having to assign an empty string or special value to indicate absence, which would need extra handling.
   
     ### 2. **Lazy Initialization of Expensive Objects**
     - If creating a member variable is costly (in terms of performance or memory), and it’s only needed sometimes, `std::optional` enables deferred construction.
       - **Example**: In a `DatabaseConnection` class, a logging connection might only be initialized if certain operations fail.
         ```cpp
         class DatabaseConnection {
         public:
             std::optional<Logger> logger;  // Initialized only when logging is needed
   
             void initLoggerIfNeeded() {
                 if (!logger) {
                     logger.emplace("logfile.txt");  // Creates the logger if it wasn't created
                 }
             }
         };
         ```
   
     ### 3. **Error-Prone or Optional Computed Values**
     - Sometimes a computed value may or may not be available, and `std::optional` can be used to signal when a calculation fails or is unnecessary.
       - **Example**: A `Rectangle` class that computes an area on demand and caches it only when needed.
         ```cpp
         class Rectangle {
         public:
             double width;
             double height;
             mutable std::optional<double> cachedArea;  // Lazy caching
   
             double area() const {
                 if (!cachedArea) {
                     cachedArea = width * height;  // Calculate and cache if not available
                 }
                 return *cachedArea;
             }
         };
         ```
   
     ### 4. **Handling Potentially Null or Absent Relationships**
     - When a class represents a relationship that might not exist or could be empty, `std::optional` can clarify that the relationship is not always populated.
       - **Example**: A `TreeNode` class representing nodes in a binary tree:
         ```cpp
         class TreeNode {
         public:
             int value;
             std::optional<std::unique_ptr<TreeNode>> left;  // Optional left child
             std::optional<std::unique_ptr<TreeNode>> right; // Optional right child
         };
         ```
   
     ### 5. **Conditionally Available Data Based on Business Logic**
     - For cases where a variable’s presence is dictated by certain business rules or application states, `std::optional` represents the absence or presence of that data clearly.
       - **Example**: In an e-commerce system, an `Order` might have a `deliveryDate` only if it has been shipped.
         ```cpp
         class Order {
         public:
             int orderID;
             std::string customerName;
             std::optional<std::string> deliveryDate; // Only available after shipment
         };
         ```
   
     Using `std::optional` improves readability by explicitly stating that certain fields may or may not be present, reducing the need for extra checks or special values and enhancing safety in your code.
