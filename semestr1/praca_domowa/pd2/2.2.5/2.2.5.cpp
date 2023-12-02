#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n >= 2) {
        int a = 1, b = 2;
        std::cout << a << " " << b << " ";
        for (int i = 3; i <= n; i++) {
            int iwyraz = a + b; 
            std::cout << iwyraz << " ";
            a = b;
            b = iwyraz;
        }
    }
    else if (n == 1)
        std::cout << 1;
    else
        std::cout << 0;
}