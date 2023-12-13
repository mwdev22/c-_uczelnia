#include <iostream>
#include "stos.hpp"

Stack::Stack() : top(nullptr) {}

Stack::Stack(const Stack& s) {
    top = nullptr;
    if (s.top != nullptr) {
        Node* temp = s.top;
        Node* new_top = new Node{temp->val, nullptr};
        top = new_top;

        Node* current = top;
        temp = temp->next;

//      kopiowanie stosu przez przechodzenie po kolejnych elementach
        while (temp != nullptr) {
            current->next = new Node{temp->val, nullptr};
            current = current->next;
            temp = temp->next;
        }
    }

}




// zwalnianie
Stack::~Stack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        std::free(temp);
    }
}

Stack& Stack::operator=(const Stack& s) {

    if (this == &s) {
        return *this; 
    }
 
    if (s.top != nullptr) {
        Node* temp = s.top;
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

bool Stack::empty() const {
    return top == nullptr;
}

void Stack::push(double num) {
    Node* temp = new Node{num, top};
    top = temp;
}

double Stack::pop() {
    double res = top->val;
    Node* temp = top;
// poprzedni element stosu jako nowy top
    top = top->next;
    std::free(temp);
    return res;
}
