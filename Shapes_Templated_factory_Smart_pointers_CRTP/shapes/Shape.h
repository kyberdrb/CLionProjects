#pragma once

namespace shapes {
    template<typename Dimension, typename ShapeType>
    class Shape {
    public:
        Shape(
                Dimension *dimension,
                ShapeType &shape)
                :
                dimension(dimension),
                shape(shape) {}

        double calculateArea() const {
            return static_cast<const ShapeType *>(this)->calculateArea();
        }

        double calculateCircumference() const {
            return static_cast<const ShapeType *>(this)->calculateCircumference();
        }

        Dimension &getDimension() const {
            return *dimension;
        }

        void changeDimension(Dimension *newDimension) {
            dimension = newDimension;
        }

        ShapeType &getShape() const {
            return this->shape;
        }

    private:
        Dimension *dimension;
        ShapeType &shape;
    };
}