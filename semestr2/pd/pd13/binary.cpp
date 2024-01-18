#include <iostream>

constexpr int binary(const unsigned int num) {
    // 0 jeśli num==0, rekurencyjne wywołania funkcji w celu uzyskania odpowiedniej liczby(0 + 2*binary(10110), potem 1+2*binary(1011) itp...)
    return num == 0 ? 0 : (num % 10 + 2 * binary(num / 10));
}

int main() {
    constexpr int b = binary(101100);
    std::cout << b << std::endl;
    return 0;
}