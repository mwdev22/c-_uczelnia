#include <cmath>
#include <iostream>


int main()
{
    int inp;
    double a, b;
    std::cin >> inp;
    std::cin >> a >> b;
    switch (inp) {
    case 1:
        std::cout << a + b << "\n";
        break;
    case 2:
        std::cout << a - b << "\n";
        break;
    case 3:
        std::cout << a * b << "\n";
        break;
    case 4:
        std::cout << a / b << "\n";
        break;
    case 5:
        std::cout << std::sqrt(a) << "\n";
        break;
    default:
        break;
    }

}