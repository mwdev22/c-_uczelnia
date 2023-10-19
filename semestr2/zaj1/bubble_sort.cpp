#include <iostream>
#include <vector>

void swap(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubble_sort(int *tab, int size){
    bool unordered;
    do{
        unordered=false;
        for(int *ptr = tab; ptr+1<tab+size; ++ptr){
            if (*ptr > ptr[1]){
                swap(ptr, ptr+1);
                unordered=true;
            }
        }
    } while (unordered);
    
    
}

int main() {
 int tab[] = {13, -2, 21, 5, -8, 5, 7, -10};
 bubble_sort(tab + 2, 4);
 for (int *ptr = tab; ptr < tab + 8;){
 std::cout << *ptr++ << " ";
 }
 std::cout << std::endl;
 return 0;
}
