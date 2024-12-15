/*

Here are two scenario-based tasks to practice function overloading in C++:

Task 1: Shape Area Calculator
Create a class Shape that provides overloaded calculateArea methods to calculate the area of different shapes (circle, rectangle, and triangle). Each shape will have a different set of parameters.

Requirements:

Overload calculateArea for a circle to take one argument, the radius.
Overload calculateArea for a rectangle to take two arguments, the length and width.
Overload calculateArea for a triangle to take two arguments, the base and height.
*/


#include <iostream>
using namespace std;

class shape {
public:
    double area(double r) {
        return 3.14 * (r * r);
    }
    friend void display(shape& s, double a, const string& st);
};

void display(shape& s, double a, const string& st) {
    cout << "Area of " << st << " is " << a << endl;
}

int main() {
    shape circle;
    double radius = 2.0;
    double area = circle.area(radius);
    display(circle, area, "circle");

    system("pause");
    return 0;
}
