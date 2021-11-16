#include <iostream>
#include <iomanip>

// Partial Template Specialization - Code duplication abstracted to a base class: https://www.learncpp.com/cpp-tutorial/137-partial-template-specialization/
// Playing with decimal precision in streams: http://www.cplusplus.com/reference/iomanip/setprecision/
// How do I remove code duplication between similar const and non-const member functions?: https://stackoverflow.com/questions/123758/how-do-i-remove-code-duplication-between-similar-const-and-non-const-member-func/123995#123995

template <class T, int size>
class StaticArrayBase {
protected:
    T m_array[size];

public:
    StaticArrayBase() : m_array() {}

    T& operator[](int index) {
        return modifyElementAtIndex(index);
    };

    const T& operator[](int index) const {
        return accessElementAtIndex(index);
    }

    const T& accessElementAtIndex(int index) const {
        return this->m_array[index];
    };

    T& modifyElementAtIndex(int index) {
        //return accessElementAtIndex(index);   // when I used the shared const function in a non-const function by itself like this
                                                // I got an error message:
                                                // error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
                                                // I need to use 'const_cast' and 'static_cast' to use the shared const function
                                                // in a non-const function
        return const_cast<T&>(static_cast<const StaticArrayBase &>(*this).accessElementAtIndex(index));
    }

    virtual void print() const = 0;

    virtual ~StaticArrayBase() = default;
};

template <class T, int size>
class StaticArray : public StaticArrayBase<T, size> {       // without defining this class I got an error message: error: ‘StaticArray’ is not a class template
public:
    void print() const override {
        for(int elementIndex = 0; elementIndex < size; ++elementIndex) {
            std::cout << this->m_array[elementIndex] << ' ';
        }
    }
};

template <int size>
class StaticArray<double, size> : public StaticArrayBase<double, size> {
public:
    void print() const override {
        for(int elementIndex = 0; elementIndex < size; ++elementIndex) {
            std::cout <<
                std::setprecision(2) << std::fixed <<
                this->m_array[elementIndex] << '\n';
        }
        std::cout << std::flush;
    }
};

class StaticArrayFiller {
public:
    template <class T, int size>
    static void fillStaticArray(StaticArrayBase<T, size>& staticArray) {
        for(int elementIndex = 0; elementIndex < size; ++elementIndex) {
            staticArray[elementIndex] = 1.12 * elementIndex + 1.01;
        }
    }
};

class StaticArrayPrinter {
public:
    template <class T, int size>
    static void printStaticArray(StaticArrayBase<T, size>& staticArray) {
        staticArray.print();
    }
};

class Tester {
public:
    static void testWholeNumbers() {
        StaticArray<int, 6> intArray;
        StaticArrayFiller::fillStaticArray(intArray);
        StaticArrayPrinter::printStaticArray(intArray);
    }

    static void testDecimalNumbers() {
        StaticArray<double, 4> doubleArray;
        StaticArrayFiller::fillStaticArray(doubleArray);
        StaticArrayPrinter::printStaticArray(doubleArray);
    }
};

int main() {
    Tester::testWholeNumbers();

    std::cout << std::endl;
    std::cout << std::endl;

    Tester::testDecimalNumbers();

    return 0;
}
