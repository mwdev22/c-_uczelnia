#ifndef _FIG_HPP_
#define _FIG_HPP_
#include <iostream>


class Figure{
    private:

    public:
        std::string color;
        Figure(std::string arg) : color(arg){};

        std::string getColor() const;

        std::ostream& print(std::ostream& stream) const;
};


class Circle: public Figure{
    private:
        double radius;
    
    public:

        Circle(std::string col, double rad) : Figure(col), radius(rad){};
        
        double getArea() const;

        double getRadius() const;

        std::ostream& print(std::ostream& stream) const;
};


class Rectangle: public Figure{
    private:
        double w;
        double h;
    public:
        Rectangle(std::string col, double width, double height) : Figure(col), w(width), h(height){};

        double getArea() const;

        double getWidth() const;

        std::ostream& print(std::ostream& stream) const;
};

#endif