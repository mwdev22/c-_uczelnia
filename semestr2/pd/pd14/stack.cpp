#include <iostream>

template <typename T>
class Stack {
    private:
        struct Node {
            T data;
            Node* next;
            Node(const T& value) : data(value), next(nullptr) {}
        };

        Node* top;

    public:
        Stack();
        ~Stack();

        bool empty() const;
        void push(const T& value);
        T pop();
};

template <typename T>
Stack<T>::Stack() : top(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
bool Stack<T>::empty() const {
    return top == nullptr;
}

template <typename T>
void Stack<T>::push(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

template <typename T>
T Stack<T>::pop() {
    if (empty()) {
        return T();  
    }

    Node* temp = top;
    T poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

int main() {
    Stack<std::string> stack;
    std::string str;
    
    while (std::cin >> str) {
        stack.push(str);
    }

    while (!stack.empty()) {
        std::cout << stack.pop() << " ";
    }

    std::cout << std::endl;
    
    return 0;
}
