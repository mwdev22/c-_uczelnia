#include <iostream>

class Set {
private:

//  podstawowa struktura drzewa
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    Node* root;

    // pomocnicze funkcje do kopiowania i usuwania setu
    void copy_tree(Node*& root, const Node* source);
    void destroy_tree(Node*& root);

public:
    Set();
    Set(const Set& s);
    ~Set();
    Set& operator=(const Set& s);

    Set& insert(int num);
    int count(int num) const;
};

Set::Set() : root(nullptr) {}

Set::Set(const Set& s) : root(nullptr) {
    copy_tree(root, s.root);
}

Set::~Set() {
    destroy_tree(root);
}

Set& Set::operator=(const Set& s) {
    if (this == &s) {
        return *this;
    }

    copy_tree(root, s.root);

    return *this;
}

Set& Set::insert(int num) {
    Node** current = &root;

    while (*current != nullptr) {
        if (num < (*current)->data) {
            current = &(*current)->left;
        } else if (num > (*current)->data) {
            current = &(*current)->right;
        } else {
            return *this;
        }
    }

    *current = new Node{num, nullptr, nullptr};
    return *this;
}

int Set::count(int num) const {
    Node* current = root;

    // przeszukiwanie drzewa w zależności od wartości num
    while (current != nullptr) {
        if (num < current->data) {
            current = current->left;
        } else if (num > current->data) {
            current = current->right;
        } else {
        // element znaleziony
            return 1;
        }
    }
    return 0;
}
void Set::copy_tree(Node*& root, const Node* source) {
    if (source == nullptr) {
        root = nullptr;
    } else {
        root = new Node{source->data, nullptr, nullptr};
        copy_tree(root->left, source->left);
        copy_tree(root->right, source->right);
    }
}
void Set::destroy_tree(Node*& root) {
    if (root != nullptr) {
        destroy_tree(root->left);
        destroy_tree(root->right);
        delete root;
        root = nullptr;
    }
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
