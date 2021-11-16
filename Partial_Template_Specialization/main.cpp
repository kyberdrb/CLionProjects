#include <iostream>

// Partial Template Specialization: https://www.learncpp.com/cpp-tutorial/137-partial-template-specialization/

template <class T, int size>
class StaticArray {
private:
    T m_array[size];

public:
    T* getArray() {
        return m_array;
    }

    T& operator[](int index) {
        return m_array[index];
    }

    void print() {
        for(int elementIndex = 0; elementIndex < size; ++elementIndex) {
            std::cout << m_array[elementIndex] << ' ';
        }
    }
};

template <int size>
class StaticArray<double, size> {
private:
    double m_array[size];

public:
    double* getArray() {
        return m_array;
    }

    double& operator[](int index) {
        return m_array[index];
    }

    void print() {
        for(int elementIndex = 0; elementIndex < size; ++elementIndex) {
            std::cout << std::scientific << m_array[elementIndex] << ' ';
        }
    }
};

int main() {
    StaticArray<int, 6> intArray{}; // interesting. the primitive datatypes work too with the generic type T of type 'class' - it doesn't have to be only 'typename'

    for(int count = 0; count < 6; ++count)
        intArray[count] = count;

    intArray.print();

    std::cout << std::endl;

    StaticArray<double, 4> doubleArray{};   // try this before and after template class specialization for double data type
    for(int count = 0; count < 4; ++count)
        doubleArray[count] = 4.0 + 0.1 * count;

    doubleArray.print();

    return 0;
}
