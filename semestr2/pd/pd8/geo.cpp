#include <iostream>
#include <cmath>

class Geometric{
    private:
        double a_0;
        double q;
    public:
        Geometric(double a_0con, double qcon) : a_0(a_0con), q(qcon) {};

        double operator[](int n) const{
            return a_0 * std::pow(q, n);
        }
};

int main() {
    const Geometric geometric(1., 0.5);
    std::cout << geometric[2] << std::endl;
    return 0;
}
