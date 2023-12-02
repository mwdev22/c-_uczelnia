#include <iostream>
#include <functional>
#include <vector>

std::vector<int>::iterator transform (std::vector<int>::const_iterator b,
                                      std::vector<int>::const_iterator e,
                                       std::vector<int>::iterator res,
                                       std::function<int(int)> op) {
    while (b != e) {
        *res++ = op(*b++);
    }
    return res;
}

int main() {
    std::vector<int> vector1 {-7, 5, 1, 2, 11};
    std::vector<int> vector2(5);

    auto result = transform(vector1.cbegin(), vector1.cend(), vector2.begin(),
        [](int element) { return element * element; });

    for (auto iterator = vector2.cbegin(); iterator < result; ++iterator) {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;

    return 0;
}
