#include <cmath>
#include <iostream>

constexpr double pi = 4. * std::atan(1.);

class Figure {
  public:
    Figure(const std::string &color): color(color) {} const std::string &getColor() const {
      return color;
    }

    std::ostream &print(std::ostream &stream) const { return stream << "Figure " << color; }

  private:
    std::string color;
};

class Circle: public Figure {
  public:
    Circle(const std::string &color, double radius): Figure(color), radius(radius) {} double getArea() const {
      return pi * radius * radius;
    }

    double getRadius() const {
      return radius;
    }

    std::ostream &print(std::ostream &stream) const {
      return stream << "Circle " << getColor() << " " << radius;
    }

  private:
    double radius;
};

class Rectangle: public Figure {
  public:
    Rectangle(const std::string &color, double width, double height):
      Figure(color), width(width), height(height) {}
    
    double getArea() const {
      return width * height;
    }
    double getWidth() const {
      return width;
    }
    double getHeight() const {
      return height;
    }
    
    std::ostream &print(std::ostream &stream) const {
      return stream << "Rectangle " << getColor() << " " << width << " " << height;
    }
  private:
    double width, height;
};


int main() {
  Figure figure("green");
  figure.print(std::cout) << std::endl;
  Circle circle("red", 1);
  circle.print(std::cout) << " " << circle.getArea() << std::endl; Rectangle rectangle("blue", 5, 4);
  rectangle.print(std::cout) << " " << rectangle.getArea() << std::endl;

  return 0;
}



