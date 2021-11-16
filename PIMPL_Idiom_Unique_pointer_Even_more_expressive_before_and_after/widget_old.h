#pragma once

#include <memory>

class widget_old {
    class old_widget_impl;
    std::unique_ptr<old_widget_impl> impl;

public:
    widget_old();

    ~widget_old();

    void foo();
};