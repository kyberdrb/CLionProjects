#include <cassert>
#include <cstdint>
#include <iostream>
#include <memory>

// Custom implementation of std::make_unique for C++11
//  Compatible with GCC versions implementing only C++11 standard
#if __cplusplus <= 201103L
namespace std {
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}
#endif

// Custom implementation of std::make_unique for C++11 without variadic templates
//  Compatible with MSVC 2010 toolchain which only partially implements C++11 standard
//  MSVC 2010 compiler doesn't support variadic templates, thus for each number of parameters
//  another overload of 'make_unique' function needs to be defined
/*#if __cplusplus <= 201103L
namespace std {
	template<typename T>
	std::unique_ptr<T> make_unique() {
		return std::unique_ptr<T>(new T());
	}

	template<typename T, typename Arg1>
	std::unique_ptr<T> make_unique(Arg1&& arg1) {
		return std::unique_ptr<T>(new T(std::forward<Arg1>(arg1)));
	}

	template<typename T, typename Arg1, typename Arg2>
	std::unique_ptr<T> make_unique(Arg1&& arg1, Arg2&& arg2) {
		return std::unique_ptr<T>(new T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2)));
	}
}
#endif*/

class ExampleClass {
public:
    explicit ExampleClass(uint32_t number) :
        _number(number)
    {}

    const uint32_t& getNumber() const {
        return this->_number;
    }

private:
    uint32_t _number;
};

int main() {
	std::unique_ptr<uint32_t> numberObj;
    numberObj = std::make_unique<uint32_t>(357);
    std::cout << "*numberObj = "<< *numberObj << std::endl;
	//std::unique_ptr<uint32_t> numberObjNew = numberObj;          // the unique_ptr cannot be copied...
	std::unique_ptr<uint32_t> numberObjNew = std::move(numberObj); // ... only moved
    std::cout << "*numberObjNew = "<< *numberObjNew << std::endl;
    assert(numberObj.get() == nullptr);
    std::cout << "numberObj.get() = "<< numberObj.get() << std::endl;

    auto exampleClass = std::make_unique<ExampleClass>(258);
    std::cout << "exampleClass->getNumber() = " << exampleClass->getNumber() << std::endl;
}
