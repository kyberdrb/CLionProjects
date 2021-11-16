#include <iostream>
#include <memory>

// Bjarne Stroustrup's C++ Style and Technique FAQ: Why don't we have virtual constructors?:
//  http://www.stroustrup.com/bs_faq2.html
//  http://webcache.googleusercontent.com/search?q=cache:BuQbEpwr1-IJ:www.stroustrup.com/bs_faq2.html+&cd=1&hl=de&ct=clnk&gl=sk
// Refactoring with more readable names, better encapsulation and smart pointers

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
    virtual std::unique_ptr<ProductA> makeProductA() const = 0;
    virtual std::shared_ptr<ProductB> makeProductB() const = 0;

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
    std::unique_ptr<ProductA> makeProductA() const override {
        return std::unique_ptr<ProductAX>(new ProductAX);
    }

    std::shared_ptr<ProductB> makeProductB() const override {
        return std::shared_ptr<ProductBX>(new ProductBX);
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
    std::unique_ptr<ProductA> makeProductA() const override {
        return std::make_unique<ProductAY>();
    }

    std::shared_ptr<ProductB> makeProductB() const override {
        return std::make_shared<ProductBY>();
    }
};

class User {
public:
    static void use(const Factory& factory) {
        factory.makeProductA();

        std::cout << std::endl;

        factory.makeProductB();
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
