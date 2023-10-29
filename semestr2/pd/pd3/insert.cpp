#include <iostream>
#include <cstdlib>

char* insert(char* str1, int ind, const char* str2) {
    
//  wyliczanie długościu napisów
    int len1 = 0;
    int len2 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }
    while (str2[len2] != '\0') {
        len2++;
    }

    char* result = (char*)std::calloc(len1 + len2 + 1, sizeof(char));

    // wstawianie do napisu kolejno elementów napisu 1 przed indeksem,
    for (int i = 0; i < ind; i++) {
        result[i] = str1[i];
    }

    // elementy napisu 2 od indeksu
    for (int i = 0; i < len2; i++) {
        result[ind + i] = str2[i];
    }
    // pozostałe elementy napisu 1, które zostały nadpisane
    for (int i = ind; i < len1; i++) {
        result[i + len2] = str1[i];
    }

    return result;
}

int main() {
    char* string = (char*)std::calloc(1, sizeof(char));

    string = insert(string, 0, "diary");
    string = insert(string, 2, "ction");

    std::cout << string << std::endl;

    std::free(string);
    return 0;
}






