#pragma once

struct Something {
    double potency;

public:
    explicit Something(double potency)
        try : potency(potency)
        {}
        catch(...) {}

    Something(const Something& source) = default;
    Something& operator=(const Something& source) = default;

    Something(Something&& source) = default;
    Something& operator=(Something&& source) = default;

    double getPotency() {
        return potency;
    }
};