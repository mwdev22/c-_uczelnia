#include <iostream>

int* getints(int* size){
    *size=0;
    int maxlen = 1;
    int* tab = (int *) std::malloc(sizeof(int));
    int n;
    while(std::cin >> n)
    {
        if (*size==maxlen){
            maxlen += 20;
            tab = (int *) std::realloc(tab, maxlen);
        }
        tab[*size] = n;
        (*size)++;
    }
    
    return tab;
}

int main() {
    int size;

    int *table = getints(&size);

    for (int index = 0; index < size;) {
        std::cout << table[index++] << " ";
    }

    std::cout << std::endl;
    std::free(table);
    return 0;
}
