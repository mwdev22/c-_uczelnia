#include <iostream>
#include <vector>


std::vector<double> operator+(const std::vector<double>& v1, const std::vector<double>& v2) {

    std::vector<double> result;

    result.reserve(v1.size()+v2.size());
    for (int i=0; i < v1.size(); ++i) {
        result.push_back(v1[i]);
    }

    for (int i=0; i < v2.size(); ++i) {
        result.push_back(v2[i]);
    }


    return result;
}

std::vector<double>& operator+=(std::vector<double>& v1, const std::vector<double>& v2) {
    for(int i=0; i<v2.size();i++){
        v1.push_back(v2[i]);
    }

    return v1;
}

int main() {
    std::vector<double> vector = std::vector<double> {6.7, -12.3} +
    std::vector<double> {-2.7, 19};
    (vector += std::vector<double> {0.5, -2.7}) +=
    std::vector<double> {19};
    for (double element: vector) {
    std::cout << element << " ";
    }
    std::cout << std::endl;
    return 0;
}