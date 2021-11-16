#pragma once

namespace circle {
    class CircleDimension {
    public:
        explicit CircleDimension(double radius);
        double getRadius() const;

    private:
        double radius{};
    };
}