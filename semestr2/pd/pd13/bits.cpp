#include <iostream>

template <typename T>
void bits(const T& num) {
    const unsigned char* bytes = (const unsigned char*)(&num);
    int numBytes = sizeof(T);

    for (int i = numBytes - 1; i >= 0; --i) {
        for (int j = 7; j >= 0; --j) {
            std::cout << ((bytes[i] >> j) & 1);
        }
        if (i > 0) std::cout << ' ';
    }

    std::cout << std::endl;
}

int main() {
    bits((short)-1);
    bits((float)-1);
    return 0;
}
