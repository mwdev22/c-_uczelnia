#include <iostream>
#include <list>

template <typename T, typename Z>
Z find(Z begin, Z end, const T& num){
    for(;begin!=end;begin++){
        if((*begin) == num){
            break;
        }
    }
    return begin;
}

int main() {
 std::list<int> c {1, 5, -3, 6, 5, 2, 4};
 auto iter = find(c.begin(), c.end(), -3);
 std::cout << std::distance(c.begin(), iter) << std::endl;
}