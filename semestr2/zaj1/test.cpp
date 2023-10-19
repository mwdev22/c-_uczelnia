#include <iostream>
#include <vector>

int main(){


    int l = 4;
    // wskaznik
    int *p = &l;

    std::cout<<p<<" "<<*p<<"\n";

    std::vector<int> v = {1,2,5,8,7};
    int *vp = &v[0];
    for(int i=0; i<v.size();i++){
        std::cout<<vp<<" "<<*vp<<"\n";
        vp++;
    }
}