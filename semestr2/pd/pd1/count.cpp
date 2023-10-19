#include <iostream>

int count(const int tab1[], const int tab2[], int num) {
    int counter = 0;
//  pętla przechodząca po elementach tablicy
    for (const int* ind = tab1; ind != tab2; ++ind) {
        if (*ind == num) {
            counter++;
        }
    }
    return counter;
}

int main() {
    const int table[] = {-1, 7, -1, 12, -5, -1, 10};
    int result = count(table, table + 7, 10);
    std::cout << result << std::endl;
    return 0;
}
