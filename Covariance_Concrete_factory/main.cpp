#include <iostream>

using std::cout;
using std::endl;

// Covariance: https://stackoverflow.com/questions/1260757/when-is-c-covariance-the-best-solution/1260934#1260934

class Product {
public:
    virtual ~Product() = default;
    virtual void play() const = 0;
};

class Factory {
public:
    virtual ~Factory() = default;
    virtual Product* create() const = 0;
};

class ConcreteProduct : public Product {
public:
    void play() const override {
        cout << "concrete product is playing..." << endl;
    }
};

class ConcreteFactory : public Factory {
public:
    ConcreteProduct* create() const override {
        return new ConcreteProduct;
    }
};

int main() {
    Factory* factory = new ConcreteFactory;
    Product* product = factory->create();

    product->play();

    delete product;
    delete factory;

    return 0;
}
