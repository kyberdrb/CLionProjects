#pragma once

namespace shapes {      // outer namespace
    namespace square {  // nested namespace
        class SquareDimension {
        public:
            explicit SquareDimension(double side);
            double getSide() const;

        private:
            double side{};
        };
    }
}