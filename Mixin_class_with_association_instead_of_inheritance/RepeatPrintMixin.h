#pragma once

template <typename Printable>
class RepeatPrintMixin {
    const Printable& printable;

public:
    explicit RepeatPrintMixin(Printable& printable) :
        printable(printable) {}

    void repeat() const {
        for (int i = 0; i < 3; ++i) {
            printable.print();
        }
    }
};