#include <iostream>

int main() {
  for (int i = 100; i < 1000; i++) {
    int setki = i / 100;
    int dziesiatki = (i % 100) / 10;
    int jednosci = i % 10;
    int suma = setki + dziesiatki + jednosci;

    if (setki < 3 || (setki >= 5 &&  setki < 8) || setki == 9) {
      if (dziesiatki == 1 || dziesiatki == 2 || dziesiatki == 4 || dziesiatki == 8) { // potęgi dwójki < 10
        if (jednosci % 2 == 0) {
          if (suma % 7 == 0) {
            std::cout << i << " ";
          }
        }
      }
    }
  }
  return 0;
}