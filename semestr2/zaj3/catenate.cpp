#include <iostream>
#include <string.h>
/*
char* catenate(std::string s1, std::string s2){
    char* res = (char *) std::malloc(20*sizeof(char));
    for(int i=0; i<s1.length();i++){
        res[i]=s1[i];
    }
    for(int i=s1.length(); i<s2.length()+s1.length();i++){
        res[i]=s2[i-s1.length()];
    }
    return res;
}*/

char* catenate(const char* s1, const char* s2){
    int len = strlen(s1)+strlen(s2);
    std::cout<<len<<std::endl;
    char* res = (char *) std::malloc(len*sizeof(char));
    int last=0;
    for(int i=0; s1[i];i++){
        res[i]=s1[i];
        last=i+1;
    }
    for(int i=0; s2[i];i++){
        res[last+i]=s2[i];
    }
    return res;
}

int main() {
char *string = catenate("pro", "duct");
std::cout << string << std::endl;
std::free(string);
return 0;
}