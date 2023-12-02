#include <vector>
#include <iostream>
#include <functional>
#include <utility>

int main(){
    std::vector<int> v{1, 2, 3, 4, 5};
    for(auto iter = v.begin(); iter < v.end();++iter){
        std::cout<<*iter<<" ";
        std::cout<<std::endl;
    }
    std::vector<int>::const_iterator it = v.begin();
    std::cout<<*it<<std::endl;
    

}