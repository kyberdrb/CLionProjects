#include <iostream>

class Document {};

// Big interface - needs to be segregated
// i.e. splitted in multiple interfaces
class IMachine {
    virtual void print(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
};

class MFP : IMachine {
    void print(Document &doc) override {
        std::cout << "MFP: printing" << std::endl;
    }

    void scan(Document &doc) override {
        std::cout << "MFP: scanning" << std::endl;
    }

    void fax(Document &doc) override {
        std::cout << "MFP: faxing" << std::endl;
    }
};

class Scanner : IMachine {
    void print(Document &doc) override {
        // What to do here? Scanner can not print.
        // - Empty body - interface is too big
        // - Throw NotImplemented exception - violates the Dependency Inversion Principle beacuse
        //     the subclass would enforce the superclass to consider the thrown exception
    }

    void scan(Document &doc) override {
        std::cout << "Scanner: scanning" << std::endl;
    }

    void fax(Document &doc) override {
        // same problem as with print method.
    }
};

// Smaller interfaces are more flexible
// which allows for greater modularity.
// IMachine pure virtual class (interface) violates the SRP principle
struct IPrinter {
    virtual void print(Document& doc) = 0;
};

struct IScanner {
    virtual void scan(Document& doc) = 0;
};

struct IFax {
    virtual void fax(Document& doc) = 0;
};

class Printer : IPrinter {
    void print(Document &doc) override {
        std::cout << "Printer: printing" << std::endl;
    }
};

class Fax : IFax {
    void fax(Document &doc) override {
        std::cout << "Fax: faxing" << std::endl;
    }
};

struct IComposedMachine : IPrinter, IFax {};

struct PrinterFax : IComposedMachine {
    IPrinter& printer;
    IFax& faxDevice;

    void print(Document &doc) override {
        printer.print(doc);
    }

    void fax(Document &doc) override {
        faxDevice.fax(doc);
    }


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}