#include <iostream>
#include <string.h>
#include <ctype.h>

void trim(char arr[]) {
    bool flag=true;
    int counter=0;
    int len = strlen(arr);
    for (int i = len-1; i!=0; i--) {
        std::cout << arr[i] << std::endl;
        if (std::isspace(arr[i])) {
            arr[i] = '\0';
        }
        else{
            break;
        }
    }
}

int main(){
    char tab[16];
    std::cin.getline(tab, 16);
    trim(tab);
    for (int i = 0; i < sizeof(tab); ++i) {
    std::cout << (int)tab[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}