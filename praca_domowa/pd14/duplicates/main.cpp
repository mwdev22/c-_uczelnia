#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    std::vector<int> check;
    int number;

    
    while (std::cin >> number) {
        numbers.push_back(number);
    }

    
    std::sort(numbers.begin(), numbers.end());

    for (auto it = std::adjacent_find(numbers.begin(), numbers.end()); it != numbers.end(); it = std::adjacent_find(it + 1, numbers.end())) {
        bool flag=true;
        for(auto i = check.begin(); i < check.end();++i){
            if(*it == *i)
                flag = false;
        }
        
        if(flag)
            std::cout << *it << " ";
            check.push_back(*it);
    }

    std::cout << std::endl;

    return 0;
}