#pragma once

namespace shapes {
    template<typename Dimension, typename ShapeType>
    class Shape {
    public:
        Shape(Dimension *dimension, ShapeType *shape) :
                dimension(dimension), shape(shape) {}

        double calculateArea() const {
            return static_cast<const ShapeType *>(this)->calculateArea();
        }

        double calculatecircumference() const {
            return static_cast<const ShapeType *>(this)->calculatecircumference();
        }

        Dimension *getDimension() const {
            return this->dimension;
        }

        void changeDimension(Dimension *newDimension) {
            this->dimension = newDimension;
        }

        ShapeType *getShape() const {
            return this->shape;
        }

    private:
        Dimension *dimension{};
        ShapeType *shape{};
    };
}