#include <iostream>
#include <ctime>

int calculate_yearday(int y, int m, int d){
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

    return yearday.tm_yday + 1;
}

int main() {
    int y, m, d;
    std::cin >> y >> m >> d;
    std::cout << calculate_yearday(y, m, d) << std::endl;
}
