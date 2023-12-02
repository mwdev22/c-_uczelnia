#include <iostream>
#include <fstream>

/*
int main()
{
   std::ifstream input("input.txt");
   std::ofstream output("output.txt");
   std::string line;
    int num = 1;
    while (std::getline(input, line)) {
        output << num << " " << line << "\n";
        ++num;
    }
}
*/
int main(int argc, char* argv[]){
    int przesuniecie = atoi(argv[1]);
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    char c;
    while(input.get(c)){
        if(c >= 65 && c <= 122){
            if(c+przesuniecie > 122)
                c = c + przesuniecie - 26;
            else if(c < 97 && c + przesuniecie > 97)
                c = c + przesuniecie - 26;
            else
                c = c + przesuniecie;
            output << c;
        }
        else{
            output<<c;
        }
    }
}
