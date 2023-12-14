#include <iostream>

class Parallelogram{
    private:
        int a,h,side;
    public:
        Parallelogram(int base, int s, int height) : a(base), side(s), h(height){};

        double area() const;
        double perimeter() const;
};

class Rectangle: public Parallelogram{
    private:
        int a,h;
    public:
    //  długość drugiego boku jest równa wysokości dla prostokątu
        Rectangle(int base, int b_len) : Parallelogram(base, b_len, b_len){};
};

class Square: public Rectangle{
    private:
        int a;
    public:
    //  boki i wysokość takie same
        Square(int a) : Rectangle(a, a){};
};  


double Parallelogram::area() const{
    return a*h;
}

double Parallelogram::perimeter() const{
    return 2*(a+side);
}


int main() {
    Parallelogram *rect = new Rectangle(4, 5);
    std::cout << rect->area() << " " << rect->perimeter() << std::endl;
    delete rect;
    Rectangle *square = new Square(6);
    std::cout << square->area() << " " << square->perimeter() << std::endl;
    delete square;
    return 0;
}
