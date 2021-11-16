#pragma once

#include <memory>

template <typename T>
class pimpl {
    std::unique_ptr<T> m;

public:
    pimpl();

    template <typename ...Args>
    explicit pimpl(Args&&...);

    ~pimpl();

    T* operator->();
    T& operator*();
};