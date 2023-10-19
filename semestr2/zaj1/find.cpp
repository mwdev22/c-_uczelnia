#include <iostream>

int* find(int *start ,int *end, int val){
    int *p = start;
    while(*p != *end){
        if (*p == val)
            return p;
        p++;
    }
    return end;
}

const int* find(const int *start ,const int *end, int val){
    const int *p = start;
    // const int *ret = p;
    while(*p != *end){
        if (*p == val)
            return p;
        p++;
    }
    return end;
}


int main() {
 int tab1[] = {13, -2, 21, 5, -8, 5, 7, -10};
 int *ptr1 = find(tab1 + 4, tab1 + 8, 5);
 const int tab2[] = {13, -2, 21, 5, -8, 5, 7, -10};
 const int *ptr2 = find(tab2 + 4, tab2 + 8, 5);
 std::cout << ptr1 - tab1 << " "<< ptr2 - tab2 << std::endl;
 return 0;
}
