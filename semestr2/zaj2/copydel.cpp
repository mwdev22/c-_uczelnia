#include <iostream>

int* remove(int* size2, const int tab[], int len, int val){
    int* res = (int *) std::malloc(len*sizeof(int));
    for(int i=0; i<len;++i){
        if(tab[i] != val){
            res[*size2]=tab[i];
            (*size2)++;
        }
    }
    return res;
}

int main() {
    const int table1[] = { 7, 3, 8, 4, 3, 3, 9, 2};
    int size2;
    int *table2 = remove(&size2, table1, 8, 3);
    for (int index2 = 0; index2 < size2; ++index2){
    std::cout << table2[index2] << " ";
    }
    std::cout << std::endl;
    std::free(table2);
    return 0;
}
