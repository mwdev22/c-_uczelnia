#include <iostream>
#include "stos.hpp"

int main() {
    Stack stack1, stack2;
    stack1.push(1.2);
    stack1.push(2.3);
    stack2 = stack1;
    Stack stack3 = stack2;

    while (!stack3.empty()) {
        std::cout << stack3.pop() << " ";
    }

    std::cout << std::endl;

    return 0;
}
