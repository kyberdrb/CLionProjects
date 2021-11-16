#include <iostream>
#include <bits/unique_ptr.h>
#include <chrono>
#include <thread>
#include "Laptop.h"

int main() {
    std::unique_ptr<Laptop> laptop = std::make_unique<Laptop>();
    std::this_thread::sleep_for (std::chrono::seconds(5));
    return 0;
}