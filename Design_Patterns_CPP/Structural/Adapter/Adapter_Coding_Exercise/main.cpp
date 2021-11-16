#include <iostream>

struct Square
{
    int side{ 0 };

    explicit Square(const int side) : side(side) {}
};

struct Rectangle
{
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const
    {
        return width() * height();
    }
};

class SquareToRectangleAdapter : public Rectangle
{
    const Square& _square;

public:
    explicit SquareToRectangleAdapter(const Square& square) : _square(square) {}

    [[nodiscard]] int width() const override {
        return _square.side;
    }

    [[nodiscard]] int height() const override {
        return _square.side;
    }
};

int main() {
    Square square{3};
    auto squareToRectangleAdapter = SquareToRectangleAdapter(square);
    std::cout << square.side << " : ";
    std::cout << squareToRectangleAdapter.height() << ", ";
    std::cout << squareToRectangleAdapter.width() << std::endl;

    std::cout << squareToRectangleAdapter.area() << std::endl;
    return 0;
}