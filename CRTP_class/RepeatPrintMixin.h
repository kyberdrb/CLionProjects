#pragma once

template <typename Printable>
class RepeatPrintMixin {
public:
    void repeatPrint() const {
        for (int i = 0; i < 3; ++i) {
            static_cast<const Printable&>(*this).print();
        }
    }
};