#include <iostream>
#include <cmath>
#include <vector>

// Base class Shape
class Shape
{
public:
    virtual double area() const = 0; // Pure virtual function for calculating area
};

// Triangle class
class Triangle : public Shape
{
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    // Calculate area of the triangle
    double area() const override
    {
        return 0.5 * base * height;
    }
};

// Rectangle class
class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Calculate area of the rectangle
    double area() const override
    {
        return length * width;
    }
};

// Circle class
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Calculate area of the circle
    double area() const override
    {
        return M_PI * radius * radius;
    }
};

int main()
{
    // List of shapes
    std::vector<Shape *> shapes = {
        new Triangle(6, 8),
        new Rectangle(3, 10),
        new Circle(5)};

    // Calculate total area covered by all shapes
    double total_area = 0;
    for (const auto &shape : shapes)
    {
        total_area += shape->area();
    }

    std::cout << "Total area covered by all shapes: " << total_area << std::endl;

    // Clean up dynamic memory
    for (const auto &shape : shapes)
    {
        delete shape;
    }

    return 0;
}