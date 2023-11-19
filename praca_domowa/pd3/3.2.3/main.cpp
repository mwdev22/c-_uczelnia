#include <iostream>



int main()
{
    double in;
    if (std::cin>>in){
        double lowest = in;
        while(std::cin>>in){
            if(in<lowest)
                lowest = in;
            }
        std::cout<<lowest;
    }
}
