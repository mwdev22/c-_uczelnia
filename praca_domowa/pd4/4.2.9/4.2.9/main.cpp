#include <iostream>

void fraction(double &integral,double &fractional, double liczba){
    int odj = liczba;
    integral = odj;
    fractional = liczba - integral;
}

int main()
{
    double integral, fractional;
    fraction(integral, fractional, 3.14159);
    std::cout << integral << " " << fractional << std::endl;
}
