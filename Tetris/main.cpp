#include <iostream>
#include <chrono>
#include <thread>

int main() {
    const char16_t OVERLINE = u'‾';

    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    std::cout << "ConstructionSite (stavenisko - hracia plocha)" << std::endl;
    std::cout << std::endl;

    std::cout << "|   |" << std::endl;
    std::cout << "|   |" << std::endl;
    std::cout << "‾‾‾‾‾" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    std::cout << "Brick (one part of a Tetromino - tehlička)" << std::endl;
    std::cout << std::endl;

    std::cout << "| # |" << std::endl;
    std::cout << "|   |" << std::endl;
    std::cout << "‾‾‾‾‾" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    std::cout << "Brick has fallen to the bottom - this brick stops moving and next brick starts falling" << std::endl;
    std::cout << std::endl;

    std::cout << "|   |" << std::endl;
    std::cout << "| # |" << std::endl;
    std::cout << "‾‾‾‾‾" << std::endl;

    std::cin.get();

    return 0;
}
