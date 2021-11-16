#pragma once

class AnotherFridge {
    class AnotherFridgeImpl;
    AnotherFridgeImpl* pimpl;

public:
    AnotherFridge();
    ~AnotherFridge();

    void coolDown();
};
