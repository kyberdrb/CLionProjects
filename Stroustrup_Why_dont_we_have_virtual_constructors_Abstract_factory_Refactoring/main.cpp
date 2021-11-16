#include <iostream>

// Bjarne Stroustrup's C++ Style and Technique FAQ: Why don't we have virtual constructors?:
//  http://www.stroustrup.com/bs_faq2.html
//  http://webcache.googleusercontent.com/search?q=cache:BuQbEpwr1-IJ:www.stroustrup.com/bs_faq2.html+&cd=1&hl=de&ct=clnk&gl=sk
// Refactoring with more readable names and better encapsulation

class ProductA {
public:
    ProductA() {
        std::cout << "Product A: created" << std::endl;
    }

    virtual ~ProductA() = default;
};

class ProductB {
public:
    ProductB() {
        std::cout << "Product B: created" << std::endl;
    }

    virtual ~ProductB() = default;
};

class Factory { // Abstract Factory
public:
    virtual ProductA* makeProductA() const = 0;
    virtual ProductB* makeProductB() const = 0;
    virtual ~Factory() = default;
};

class ProductAX : public ProductA {
public:
    ProductAX() {
        std::cout << "Product AX: created" << std::endl;
    }
};

class ProductBX : public ProductB {
public:
    ProductBX() {
        std::cout << "Product BX: created" << std::endl;
    }
};

class FactoryX : public Factory {
public:
    ProductAX* makeProductA() const override {
        return new ProductAX;
    }

    ProductBX* makeProductB() const override {
        return new ProductBX;
    }
};

class ProductAY : public ProductA {
public:
    ProductAY() {
        std::cout << "Product AY: created" << std::endl;
    }
};

class ProductBY : public ProductB {
public:
    ProductBY() {
        std::cout << "Product BY: created" << std::endl;
    }
};

class FactoryY : public Factory {
public:
    ProductAY* makeProductA() const override {
        return new ProductAY;
    }

    ProductBY* makeProductB() const override {
        return new ProductBY;
    }
};

class User {
public:
    static void use(const Factory& factory) {
        ProductA* p = factory.makeProductA();

        std::cout << std::endl;

        ProductB* q = factory.makeProductB();

        delete q;
        delete p;
    }
};

int main() {
    FactoryX factoryX;
    FactoryY factoryY;

    std::cout << "FactoryX" << std::endl;
    User::use(factoryX);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    std::cout << "FactoryY" << std::endl;
    User::use(factoryY);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    std::cout << "FactoryX" << std::endl;
    User::use(FactoryX());

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    std::cout << "FactoryY" << std::endl;
    User::use(FactoryY());

    return 0;
}
