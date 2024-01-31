#include <iostream>

template<typename T>
T sum(T value) {
    return value;
}

template<typename T, typename... Args>
T sum(T first, Args... args) {
    return first + sum(args...);
}

int main() {
    std::cout << sum(6) << " " << sum(1, 2, 3) << std::endl;
    return 0;
}
