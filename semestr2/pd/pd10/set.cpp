#include <iostream>


class Set{
    private:
        struct Node {
            double data;
            Node* next; 
        };
        Node* top;

    public:

    Set();
    ~Set();

    Set& insert(double num);

    double count(double num) const;

    Set& operator=(const Set& s);
};

Set::Set() : top(nullptr){}

Set::~Set(){
    Node* current = top;
    while(current!=nullptr){
        Node* temp = current;
        current = temp->next;
        std::free(temp);
    }
}

Set& Set::operator=(const Set& s){
    Node* new_top = s.top;

    if (this == &s) {
        return *this; 
    }
    
    if(s.top!=nullptr){
        Node* temp = s.top;
        Node* new_top = new Node{temp->data, nullptr};
        top = new_top;

        Node* current = top;
        temp = temp->next;

        while (temp != nullptr) {
            current->next = new Node{temp->data, nullptr};
            current = current->next;
            temp = temp->next;
        }
    }
    return *this;
}

Set& Set::insert(double num){
    Node* temp = top;
    Node* new_top = this->top;
    if(top!=nullptr){
        while (temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next = new Node{num, nullptr};
    }else{
        this->top = new Node{num, nullptr};
    }

    return *this;
    
}

double Set::count(double num) const{
    Node* temp = top;
    while(temp!=nullptr){
        if(temp->data==num){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}


int main() {
    Set set1, set2;
    set1.insert(1);
    (set2 = set1).insert(1).insert(3);
    const Set set3 = Set(set2).insert(4);
    for (int key = 0; key < 5; ++key) {
    std::cout << set1.count(key) << " ";
    }
    std::cout << std::endl;
    for (int key = 0; key < 5; ++key) {
    std::cout << set2.count(key) << " ";
    }
    std::cout << std::endl;
    for (int key = 0; key < 5; ++key) {
    std::cout << set3.count(key) << " ";
    }
    std::cout << std::endl;
    return 0;
}
