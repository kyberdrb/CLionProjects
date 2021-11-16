#include <iostream>

class Rectangle {
protected:
    int m_width, m_height;

public:
    Rectangle(int width, int height) : m_width(width), m_height(height) {};

    int getWidth() const {
        return m_width;
    }

    virtual void setWidth(int width) {
        Rectangle::m_width = width;
    }

    int getHeight() const {
        return m_height;
    }

    virtual void setHeight(int height) {
        Rectangle::m_height = height;
    }
};

class Square : public Rectangle {
public:
    explicit Square(int size) : Rectangle(size, size) {};

    void setWidth(int width) override {
        Rectangle::m_width = Rectangle::m_height = width;
    }

    void setHeight(int height) override {
        Rectangle::m_width = Rectangle::m_height = height;
    }
};

void process(Rectangle& rectangle) {
    int width = rectangle.getWidth();
    rectangle.setHeight(10);
    std::cout << "Expected area: " << (width * 10);
    std::cout <<
        "\tActual area: " <<
        (rectangle.getWidth() * rectangle.getHeight()) <<
        std::endl;
}

int main() {
    Rectangle rectangle{3, 4};
    process(rectangle);

    Square square{5};
    process(square);

    return 0;
}