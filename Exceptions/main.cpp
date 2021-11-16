#include <iostream>

enum Error {
    ERROR_1, ERROR_2
};

class MyException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Something bad happened";
    }
};

class Test {
public:
    void goesWrong() {
        throw MyException();
    }
};

class CanGoWrong {
public:
    void canGoWrong() {
        char* pMemory = new char[9999999999];
        delete [] pMemory;
    }

};

void exercise_4();
void exercise_5();
void exercise_6();
void goesWrong(Error error);

int main() {
    exercise_4();
    exercise_5();
    exercise_6();

    return 0;
}

void exercise_4() {
    CanGoWrong wrong;
    try {
        wrong.canGoWrong();
    } catch (std::bad_alloc &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Still running..." << std::endl;
}

void exercise_5() {
    Test test;

    try {
        test.goesWrong();
    } catch (MyException& e) {
        std::cout << e.what() << std::endl;
    }
}

void exercise_6() {
    try {
        Error error = ERROR_1;
        goesWrong(error);
    } catch (std::bad_alloc& e) {
        std::cout << "Handling bad_alloc exception" << std::endl;
        std::cout << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Handling general exception" << std::endl;
        std::cout << e.what() << std::endl;
    }
}

void goesWrong(Error error) {
    switch (error) {
        case ERROR_1:
            throw std::bad_alloc();
            break;
        case ERROR_2:
            throw std::exception();
            break;
    }

}
