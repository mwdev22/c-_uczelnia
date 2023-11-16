#include <iostream>
#include <cstdlib>
#include <cstring>

struct Node {
  Node *left;
  Node *top;
  Node *right;

  char str[10];
};

bool insert_node(Node **head, const char *str){
//  alokacja pamięci dla nowego węzła
    Node** new_node = (Node**)std::malloc(sizeof(Node**)); 
    (*new_node)->left = nullptr;
    (*new_node)->right = nullptr;

//  wpisywanie znkau do węzła, jeśli jego str jest pusty
    if((*head)->str[0] == '\0'){
        strcpy((*new_node)->str, str);
        return true;
    }
//  rekurencyjne wywoływanie funkcji w zależności od długości napisu, aby wstawić nowy węzeł w odpowiednie miejsce 
    else if(strlen(str) < strlen((*head)->str)){
        insert_node(&((*new_node)->left), str);
    }
    else if(strlen(str) > strlen((*head)->str)){
        insert_node(&((*new_node)->left),str);
    }
// przypadek, gdy element jest juz w drzewie
    return false;

};
/*
void free_tree(Node **head){

    // czyszczenie pamieci z kolejnych węzłów
    if((*head)->left){
        std::free((*head)->left);
    }
    else if((*head)->top){
        std::free((*head)->top);
    }
    else if((*head)->right){
        std::free((*head)->right);
    }
    else if((*head)->str){
        std::free((*head)->str);
    }
};*/

void prints(const Node *head) {
  if (head->left) {
    prints(head->left);
  }

  if (head->right) {
    prints(head->right);
  }

  std::cout << head->str << std::endl;
}

int main() {
  Node *head = nullptr;

  insert_node(&head, "ekierka");
  insert_node(&head, "abecadlo");
  insert_node(&head, "wierzba");

  prints(head);
  
//   free_tree(&head);

  return 0;
}
