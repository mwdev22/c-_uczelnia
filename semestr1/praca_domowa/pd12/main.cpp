#include <iostream>
#include <vector>
#include <functional>
/*
std::vector<int>::iterator partial_sum(std::vector<int>::const_iterator b,
                                        std::vector<int>::const_iterator e,
                                         std::vector<int>::iterator result) {
    if (b == e) {
        return result;
    }

    *result = *b;
    auto prev = *b;
    ++b;
    ++result;

    while (b != e) {
        *result = *b + prev;
        prev = *result;
        ++b;
        ++result;
    }

    return result;
}*/
template <typename Iterator>
Iterator min_element(Iterator begin, Iterator end) {
    if (begin == end) {
        return end;  
    }

    auto min_it = begin;
    ++begin;  

    for (; begin != end; ++begin) {
        if (*begin < *min_it) {
            min_it = begin;  
        }
    }

    return min_it;
}

int main() {
    std::vector<int> vector {7, 5, 1, 12, 8};
    auto result1 = min_element(vector.begin(), vector.end());
    auto result2 = min_element(vector.cbegin(), vector.cend());
    std::cout << result1 - vector.begin() << " " << result2 - vector.cbegin() << std::endl;
    return 0;
}