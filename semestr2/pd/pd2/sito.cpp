#include <iostream>
#include <cstdlib>

void eratosthenes(int n) {
    if (n <= 1) {
        return;
    }
//  tablica do wykreślania liczb, wszystkie inicjalizuje jako true przed wykreślaniem
    bool isPrime[n + 1];
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

//  wykreślenie wielokrotności liczb pierwszych, począwszy od 2 do n
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
        //  wielokrotności każdy liczby pierwszej oznaczamy jako false
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

//  wynik operacji sita
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            std::cout << i << " ";
        }
    }
}

int main(int argc, char* argv[]) {

//  sufit dla liczb pierwszych pobrany z argumentu wywołania
    int n = std::atoi(argv[1]);

    eratosthenes(n);

    return 0;
}
