#include <iostream>

// konstrukcja bardzo podobna do stosu z labów
class Queue{
    private:
        struct Node {
            double val;
            Node* next;
        };
        Node* top;

    public:
//      konstruktory
        Queue();
        Queue(const Queue& q);
        ~Queue();

//      operatory
        Queue& operator=(const Queue& q);
//      metody
        Queue& push(double num);
        bool empty() const;
        double pop();
};

Queue::Queue() : top(nullptr){};

Queue::Queue(const Queue& q) {
    top = nullptr;
    if (q.top != nullptr) {
        Node* temp = q.top;
        Node* new_top = new Node{temp->val, nullptr};
        top = new_top;

//      głębokie kopiowanie
        Node* current = top;
        temp = temp->next;

        while (temp != nullptr) {
//      tworzenie kolejnych warstw kolejki i kopiowanie do nich wartości
            current->next = new Node{temp->val, nullptr};
            current = current->next;
            temp = temp->next;
        }
    }

}

Queue::~Queue(){
//  zwalnianie pamięci z kolejnych elementów kolejki
    while(top!=nullptr){
        Node* temp = top;
        top = top->next;
        std::free(temp);
    }
}

Queue& Queue::operator=(const Queue& q){

    if (this == &q) {
        return *this; 
    }

    if(q.top!=nullptr){
        Node* temp = q.top;
        Node* new_top = new Node{temp->val, nullptr};
        top = new_top;

        Node* current = top;
        temp = temp->next;

        while (temp != nullptr) {
            current->next = new Node{temp->val, nullptr};
            current = current->next;
            temp = temp->next;
        }
    }
    return *this;
}

bool Queue::empty() const{
    return top==nullptr;
}

Queue& Queue::push(double num){

    Node* current = this->top;
    if(current!=nullptr){
    //  przejście po wszystkich elementach kolejki, w celu wstawienia nowego na koniec
        while(current->next!=nullptr){
            current = current->next;
        }
        current->next = new Node{num, nullptr};
    }else{
        this->top = new Node{num, nullptr};
    }
    return *this;
}

double Queue::pop(){
    double val = top->val;
    Node* temp = top;
    top = temp->next;
    std::free(temp);
    return val;
}



int main() {
    Queue queue1, queue2;
    queue1.push(1.2);
    (queue2 = queue1).push(2.3);
    Queue queue3 = Queue(queue2).push(3.4);
    
    while (!queue1.empty()) {
        std::cout << queue1.pop() << " ";
    }
        std::cout << std::endl;
    while (!queue2.empty()) {
        std::cout << queue2.pop() << " ";
    }
        std::cout << std::endl;
    while (!queue3.empty()) {
        std::cout << queue3.pop() << " ";
    }
        std::cout << std::endl;
    return 0;
}