#include <iostream>
#include <vector>
#include <fstream>

int main(){
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    std::string line;
    for(;std::getline(input, line);){
        std::cout<<line<<std::endl;
        output<<line<<std::endl;
    }
    input.close();
    output.close();
}