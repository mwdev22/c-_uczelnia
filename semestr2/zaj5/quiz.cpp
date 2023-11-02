#include <iostream>
#include <random>  

struct Q {
    int a;
    int b;
};

int rand_nums(){
    std::random_device rand;  
    std::mt19937 gen(rand());  
    std::uniform_int_distribution<>dis(1, 10);  
    int random_number = dis(gen);
    return random_number;  
}

void swap(Q &a, Q &b){
    Q temp = b;
    b = a;
    a = temp;
}

void bbsort(Q quiz []){
    bool unordered=true;
    do{
        unordered=false;
        for(int i=0; i != 10 ;i++){
            int a = quiz[i].a * quiz[i].b;
            int b = quiz[i+1].a * quiz[i+1].b;
            if( a > b){
                swap(quiz[i], quiz[i+1]);
                unordered=true;
            }
        }
    }while (unordered);
}


void create_ins(Q &ins){
    ins.a = rand_nums();
    ins.b = rand_nums();
}

int main(){
    Q quiz[10];
    Q temp;

    bool flag = true;
    int ans;
    for(int i=0;i<10;i++){
        while (quiz[i].a != temp.a){
            create_ins(temp);
            for(int j=0; j<i; j++){
                if (temp.a == quiz[j].a && temp.b == quiz[j].b){
                    flag = false;
                }
                if(flag){
                    quiz[i] = temp;
                }
            }
        }
    }

    bbsort(quiz);

    for(int i=0; i<10; i++){
        std::cout<<quiz[i].a<<" "<<quiz[i].b<<std::endl;
        std::cin>>ans;
        while(ans != (quiz[i].a*quiz[i].b)){
            std::cin>>ans;
        }
    }
}