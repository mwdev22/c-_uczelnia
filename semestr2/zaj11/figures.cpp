#include <iostream>
#include <fstream>
#include <cmath>
#include "fig.hpp"

// figure
std::string Figure::getColor() const{
            return color;
        }
std::ostream& Figure::print(std::ostream& stream) const{
            stream<<"Figure "<<color;
            return stream;
        }

double Circle::getArea() const{
            return M_PI * (pow(radius,2));
        }

double Circle::getRadius() const{
            return radius;
        }
std::ostream& Circle::print(std::ostream& stream) const{
            stream<<"Circle "<<color<<" "<<radius;
            return stream;
        }

double Rectangle::getArea() const{
            return w*h;
        }
double Rectangle::getWidth() const{
        return w;
}

std::ostream& Rectangle::print(std::ostream& stream) const{
            stream<<"Rectangle "<<color;
            return stream;
}



