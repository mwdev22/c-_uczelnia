#include <iostream>

template <int n>
class Modulo {
private:
    int value;

public:
    Modulo();
    Modulo(int val);

    Modulo& operator++();
    Modulo operator++(int);
    Modulo operator+(const Modulo& other) const;
    Modulo operator*(const Modulo& other) const;

    friend std::istream& operator>>(std::istream& is, Modulo& mod);
    friend std::ostream& operator<<(std::ostream& os, const Modulo& mod);
};

template <int n>
Modulo<n>::Modulo() : value(0) {}

template <int n>
Modulo<n>::Modulo(int val) : value(val % n) {
    if (value < 0) {
        value += n;
    }
}

template <int n>
Modulo<n>& Modulo<n>::operator++() {
    value = (value + 1) % n;
    return *this;
}

template <int n>
Modulo<n> Modulo<n>::operator++(int) {
    Modulo temp(*this);
    ++(*this);
    return temp;
}

template <int n>
Modulo<n> Modulo<n>::operator+(const Modulo& other) const {
    return Modulo(value + other.value);
}

template <int n>
Modulo<n> Modulo<n>::operator*(const Modulo& other) const {
    return Modulo(value * other.value);
}

template <int n>
std::istream& operator>>(std::istream& is, Modulo<n>& mod) {
    int input;
    is >> input;
    mod = Modulo<n>(input);
    return is;
}

template <int n>
std::ostream& operator<<(std::ostream& os, const Modulo<n>& mod) {
    os << mod.value;
    return os;
}

int main() {
    Modulo<16> modulo1, modulo2;
    std::cin >> modulo1 >> modulo2;
    std::cout << modulo1 + modulo2 << " " << modulo1 * modulo2 << std::endl;
    std::cout << ++modulo1 << " " << modulo2++ << std::endl;
    return 0;
}
