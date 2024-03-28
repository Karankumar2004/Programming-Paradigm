#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Shape
{
public:
    virtual double area() const = 0;
};

class Triangle : public Shape
{
private:
    double base;
    double height;

public:
    Triangle(double base, double height) : base(base), height(height) {}

    double area() const override
    {
        return 0.5 * base * height;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double area() const override
    {
        return length * width;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double area() const override
    {
        return M_PI * radius * radius;
    }
};

class ShapeManager
{
private:
    vector<Shape *> shapes;

public:
    void addShape(Shape *shape)
    {
        shapes.push_back(shape);
    }

    double getTotalArea() const
    {
        double totalArea = 0.0;
        for (const auto &shape : shapes)
        {
            totalArea += shape->area();
        }
        return totalArea;
    }
};

int main()
{
    ShapeManager manager;

    // Add some shapes
    manager.addShape(new Triangle(5, 8));
    manager.addShape(new Rectangle(4, 6));
    manager.addShape(new Circle(3));

    // Calculate total area
    double totalArea = manager.getTotalArea();

    cout << "Total area covered by the shapes: " << totalArea << endl;

    // Free the memory
    for (const auto &shape : manager)
    {
        delete shape;
    }

    return 0;
}
