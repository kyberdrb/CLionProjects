#include "pimpl_h.h"

class widget {
    class impl;
    pimpl<impl> m;

public:
    void bar();
};
