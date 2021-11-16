#pragma once

namespace square {
    class SquareDimension {
    public:
        explicit SquareDimension(double side);
        double getSide() const;

    private:
        double side{};
    };
}