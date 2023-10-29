#include <iostream>

bool compare(const char* word1,const char* word2){
    int i=0;
    while(word1[i] && word2[i]){
        std::cout<<word1[i]<<" "<<word2[i]<<std::endl;
    //  sprawdzanie pozycji liter w tablicy ascii,
    // gdy litera pierwszego wyrazu jest pierwsza, oznacza to pierwszeństwo w kolejności alfabetycznej
    // przy założeniu, że na wejściu są tylko małe litery 
        if(word1[i]>word2[i]){
            return false;
        }
        else if (word1[i]<word2[i])
        {
            return true;
        }
        i++;
    }
    // gdy pierwszy wyraz zapobiegł wejściu do pętli, oznacza że jest pierwszy w kolejności alfabetycznej
    return (word1[i] == '\0');
}

int main() {
    std::cout << std::boolalpha << compare("rower", "rowerowy");
    std::cout << std::endl;
    return 0;
}

