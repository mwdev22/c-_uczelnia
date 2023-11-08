#include <iostream>
#include <cstdlib> 

// struktura zawierająca numer, wskaźnik na prawy i lewy węzeł
struct Node {
    int data;
    Node* left;
    Node* right;
};

// tworzenie nowego węzła drzewa
Node* GetNewNode(int data){
    Node* new_node = (Node*)std::malloc(sizeof(Node)); 
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

Node* Insert(Node* root, int data){
    if(root == NULL){
        root = GetNewNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(Node* root, int value){
    if(root==NULL) return false;
    else if(root->data == value) return true;
    else if (value <= root->data) return Search(root->left, value);
    else return Search(root->right, value);
}

Node* root = NULL;

int main(){
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);


    std::cout<<root->data<<std::endl;

    std::cout<<std::boolalpha<<Search(root, 11)<<std::endl;
    return 0;
}
