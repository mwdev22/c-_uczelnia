#include <iostream>
#include "fig.hpp"



int main() {
    Figure figure("green");
    figure.print(std::cout) << std::endl;
    Circle circle("red", 1);
    circle.print(std::cout) << " " <<
    circle.getArea() << std::endl;
    Rectangle rectangle("blue", 5, 4);
    rectangle.print(std::cout) << " " <<
    rectangle.getArea() << std::endl;
    return 0;
}
