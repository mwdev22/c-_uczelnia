#include <iostream>

int main()
{
    int hour, min;
    std::cin >> hour >> min;
    std::cout << std::boolalpha << (hour == 10 && min >= 30 || (hour == 18 && min < 30) || (hour > 10 && hour < 18));
}

