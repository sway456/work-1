#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual function
    virtual double getArea() = 0;
};

// Derived class 1
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
    double getArea() {
        return width * height;
    }
};

// Derived class 2
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double getArea() {
        return 3.14 * radius * radius;
    }
};

int main() {
    // Create a rectangle object
    Rectangle rect(5, 10);

    // Create a circle object
    Circle circle(7);

    // Call the getArea() function for each object
    cout << "Area of rectangle: " << rect.getArea() << endl;
    cout << "Area of circle: " << circle.getArea() << endl;

    return 0;
}
