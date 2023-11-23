#include <iostream>
#include <cmath>

class Turtle {
    private:
        double xpos;
        double ypos;
        double angle;

    public:
    // konstruktor z domyślnymi wartościami
        Turtle() : xpos(0), ypos(0), angle(0) {}

    // funkcje zwracające koordynaty żółwia
        double x() const { return xpos; }

        double y() const { return ypos; }

        Turtle& go(double distance);

        Turtle& turn(double degrees);
};

// obracanie żółwia
Turtle& Turtle::turn(double degrees) {
    angle += degrees;
// utrzymanie kąta w zakresie 0-360
    if(angle>360.0){
        angle-=360.0;
    }
    return *this;
}

// przemieszczanie żółwia
Turtle& Turtle::go(double distance) {
    xpos += distance * cos(angle * M_PI / 180.0);
    ypos += distance * sin(angle * M_PI / 180.0);
    return *this;
}

int main() {
    Turtle turtle;
    turtle.turn(30.0).go(100.0);
    std::cout << turtle.x() << " " << turtle.y() << std::endl;
    return 0;
}
