/*
Cognome: Balcan
Nome: Stelian Gabrielle
Classe: 4C
Esercizio: BSTs Library
*/
 
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* l_child;
    Node* r_child;
    Node(int n){
        data = n;
        l_child = r_child = nullptr;
    }
};

Node* insert(Node* root, int valore);
bool search(Node* root, int valore);


int main(){
    
    system("PAUSE");
    return 0;
}

Node* insert(Node* root, int valore){
    if(root == nullptr){
        return new Node(valore);
    }
    if(root->data == valore){
        return root;
    }

    if(valore > root->data){
        root->r_child = insert(root->r_child, valore);
    }else{
        root->l_child = insert(root->l_child, valore);
    }

    return root;
}

bool search(Node* root, int valore){
    while(root != nullptr){
        if(root->data == valore){
            return true;
        }

        if(valore > root->data){
            root = root->r_child;
        }else{
            root = root->l_child;
        }
    }
    return false;
}