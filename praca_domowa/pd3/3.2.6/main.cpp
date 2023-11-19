#include <iostream>
#include <cmath>

int main()
{
    double a,b;
    std::cin>>a>>b;
    double total_length,x,y;
    while(std::cin>>x>>y){
       total_length+=std::sqrt(std::pow((x-a),2)+ std::pow((y-b),2));
       a = x;
       b = y;
    }
    std::cout<<total_length<<std::endl;
}
