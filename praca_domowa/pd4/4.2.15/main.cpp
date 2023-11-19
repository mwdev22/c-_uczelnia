#include <iostream>

bool prime(int liczba){
    int check=0;
    for (int i=1; i<=liczba; i++){
        switch(liczba%i==0){
            case true:check+=1;
            default:break;
        }
    }
    switch (check){
        case 2:return true;
        default:return false;
    }
}

int main() {
std::cout << std::boolalpha << prime(13) << std::endl; }
