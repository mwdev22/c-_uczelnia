#include <iostream>
#include <cstring>

char *read_word(){
    // wielkość i max wielkość
    int size = 0;
    int max = 10;

    char c;

//  alokacja pamięci z max capacity, przykładowo 10 na start
    char *word = (char*)malloc(max*sizeof(char));

// pobieranie znaku, wczytanie znaku białego oznacza, że wczytaliśmy całe słowo
    while(std::cin.get(c) && !std::isspace(c)){
        word[size++]=c;
// realloc w przypadku za małej ilości zaalokowanej pamięci
         if (size == max) {
            max +=5;
            word = (char*)realloc(word, max*sizeof(char));
        }
    }

    // ostatni element wyrazu jako znak końca stringu
    word[size] = '\0';

    return word;
}

char** read_words(int *size){

    size = 0;
    int max=100;

    char **words = (char**)malloc(max*sizeof(char*));

    char *word = nullptr;

    // wczytywanie kolejnych wyrazów
    while(word=read_word()){
        (*size)++;
        if (*size == max) {
            max +=5;
            word = (char*)realloc(word, max*sizeof(char));
        }
        words[*size++] = word;
    };

    return words;
}

void sort(char *tab[], int size){
    bool unordered;

    do{
        for(int i=0; i+1 < size; ++i){
            if(std::strcmp(tab[i+1], tab[i]) < 0){
                char* temp = tab[i+1];
                tab[i+1] = tab[i];
                tab[i] = temp;
                unordered=true;
            }
        }
    }while(unordered);
}

int main(){

    int size;

    // tablica 2wymiarowa
    char **words = read_words(&size);
    sort(words, size);

    std::cout<<size<<std::endl;
    for(int i=0; i < size; ++i ){
        std::cout<< words[i]<<" ";
    }
    std::cout<<std::endl;

    // zwalnianie pamięci w 2 wymiarze tablicy
    for(int i=0; i < size; ++i ){
        std::free(words[i]);
    }

    std::free(words);

}