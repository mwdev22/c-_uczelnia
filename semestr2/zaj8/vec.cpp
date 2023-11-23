#include <iostream>


class Vector {
    private:
        double x;
        double y;
    public:
        Vector(double x1,double y1) : x(x1), y(y1) {}; 


        friend std::ostream& operator<<(std::ostream&, const Vector &v);

        friend Vector operator+(const Vector &v1, const Vector &v2);
        Vector operator-(const Vector& v) const;

        Vector& operator-=(const Vector& v);

        friend Vector& operator+=(Vector &v1, const Vector &v2);

};

Vector operator+(const Vector &v1, const Vector &v2){
    return Vector(v1.x+v2.x, v1.y+v2.y);
}

Vector Vector::operator-(const Vector& v) const {
    return Vector(x - v.x, y - v.y);
}

Vector& operator+=(Vector &v1, const Vector &v2){
    v1.x += v2.x;
    v1.y+=v2.y;
    return v1;
}
Vector& Vector::operator-=(const Vector& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector &v){
  stream<<v.x<<" "<<v.y<<std::endl;
  return stream;
}


int main() {
    std::cout << Vector(3.5, -8.3) + Vector(0.5, 0.3)
    << std::endl;
    std::cout << Vector(3.5, -8.3) - Vector(0.5, 0.3)
    << std::endl;

    Vector vector1(10, 10);
    Vector vector2(1, 1);
    (vector1 += vector2) += Vector(0.1, 0.1);
    std::cout << vector1 << " " << vector2 <<
    std::endl;

    (vector1 -= vector2) -= Vector(0.1, 0.1);
    std::cout << vector1 << " " << vector2 <<
    std::endl;

    return 0;
}
