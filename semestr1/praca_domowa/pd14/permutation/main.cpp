#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <numeric>

// permutation

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 

    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    std::iota(numbers.begin(), numbers.end(), 0); 

    std::random_shuffle(numbers.begin(), numbers.end()); 

    
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}