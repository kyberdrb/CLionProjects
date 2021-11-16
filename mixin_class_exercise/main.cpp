#include <iostream>
#include <string>
#include <cstdint>
#include <memory>

class Name {
public:
    explicit Name(std::string name) : name(std::move(name)) {}

    void print() const {
        std::cout << name << "\n";
    }

private:
    std::string name;
};

class Age {
public:
    explicit Age(uint8_t age) : age(age) {}

    void print() const {
        std::cout << unsigned(age) << "\n";
    }

private:
    uint8_t age{};
};

template <typename Printable>
class RepeatPrinter : public Printable {
public:
    explicit RepeatPrinter(const Printable& printable) : Printable(printable) {}

    void repeatPrint(uint8_t times) const {
        for (uint8_t time = 0; time < times; ++time) {
            Printable::print();
        }
    }
};

class RepeatPrinterFactory {
public:
    template <typename Printable>
    static std::unique_ptr<RepeatPrinter<Printable>> wrapIntoRepeatPrinterMixin(const Printable& printable) {
        return std::make_unique<RepeatPrinter<Printable>>(printable);
    }
};

int main() {
    Name name("John");
    name.print();

    std::cout << "\n";

    std::unique_ptr<RepeatPrinter<Name>> nameWithRepeating = std::make_unique<RepeatPrinter<Name>>(name);
    nameWithRepeating->repeatPrint(3);

    std::cout << "\n";

    RepeatPrinterFactory::wrapIntoRepeatPrinterMixin(name)->repeatPrint(2);

    std::cout << "\n";

    auto age = std::make_unique<Age>(42);
    age->print();

    std::cout << "\n";

    auto ageWithRepeating = RepeatPrinterFactory::wrapIntoRepeatPrinterMixin(*age);
    ageWithRepeating->repeatPrint(2);

    std::cout << "\n";

    RepeatPrinterFactory::wrapIntoRepeatPrinterMixin(*age)->repeatPrint(3);

    std::cout << "\n";

    return 0;
}
