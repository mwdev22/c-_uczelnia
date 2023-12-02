#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

int main(){
    std::vector<int> v(5);
    int liczba = 0; 
    fill(v.begin(),v.end(), 2); // wypełnianie wektora dwójkami
    for(auto i = v.cbegin(); i < v.cend();){
        std::cout << *i++ << " ";
    }
    // wpisuje do kolejmych elementów wycinka wyniki funkcji
    generate(v.begin(), v.end(), [] {return 2; }); 

    // zastępowanie elementów wektora
    replace(v.begin(), v.end(), 2, 8);
    replace_if(v.begin(), v.end(), [](int n) {return n < 0; }, 8);

    // odwrócenie elementów
    reverse(v.begin(), v.end());

    // przesunięcie cykliczne, 2 argument na początku vectora
    rotate(v.begin(), v.begin() + 2, v.end());

    // pasujące elementy na początek vectora
    stable_partition(v.begin(), v.end(), [](int n) {return n < 0; });

    random_shuffle(v.begin(), v.end());
     
}