#include <iostream>
#include <ctime>

int main() {
    int y, m, d;
    std::cin >> y >> m >> d;

    // inicjalizacja struktury
    tm yearday;
    yearday.tm_year = y - 1900; // rok musi być przesunięty o 1900, ponieważ od 1900 jest indeksowany
    yearday.tm_mon = m - 1; // miesiące są indeksowane od 0
    yearday.tm_mday = d;

    // pola dotyczące godziny ustawiamy na 0
    yearday.tm_hour = 0;
    yearday.tm_min = 0;
    yearday.tm_sec = 0;

    std::mktime(&yearday);

    std::cout << yearday.tm_yday + 1 << std::endl; // +1, ponieważ tm_yday indeksowane jest od 0
}
