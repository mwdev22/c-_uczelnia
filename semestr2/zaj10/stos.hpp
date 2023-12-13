#ifndef _STACK_HPP_
#define _STACK_HPP_
#include <iostream>



class Stack {
private:
    struct Node {
        double val;
        Node* next;
    };
    Node* top;

public:
    // konstruktory
    Stack();
    Stack(const Stack& s);
    ~Stack();

    // operator
    Stack& operator=(const Stack& s);

    bool empty() const;
    void push(double num);
    double pop();
};
#endif
