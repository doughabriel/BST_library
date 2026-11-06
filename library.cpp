/*
Cognome: Balcan
Nome: Stelian Gabrielle
Classe: 4C
Esercizio: BSTs Library (Class refactoring)
*/

#include <iostream>
using namespace std;

class Node {
private:

    int data;
    Node* left;
    Node* right;

public:

    Node(int k){
        data = k;
        left = right = nullptr;
    }

    int getData(){
        return data;
    }

    Node* getLeft(){
        return left;
    }

    Node* getRight(){
        return right;
    }

    void setData(int n){
        data = n;
    }

    void setLeft(Node* n){
        left = n;
    }

    void setRight(Node* n){
        right = n;
    }

    bool isLeaf(){
        if(left == nullptr && right == nullptr){
            return true;
        }
        
        return false;

    }

    void inOrder(){
        left->inOrder();
        cout << getData() << " ";
        right->inOrder();
    }

    int height(){
        if(left == nullptr && right == nullptr){
            return 1;
        }

        int leftHeight = 0;
        int rightHeight = 0;

        if(left != nullptr){
            leftHeight = left->height();
        }
        
        if(right != nullptr){
            rightHeight = right->height();
        }

        if(leftHeight > rightHeight){
            return 1 + leftHeight;
        }

        return 1 + rightHeight;

    }

    int contaFoglie(){
        if(isLeaf()){
            return 1;
        }

        int count = 0;

        if(left != nullptr){
            count = count + left->contaFoglie();
        }

        if(right != nullptr){
            count = count + right->contaFoglie();
        }

        return count;

    }

    void svuota(){
        if(left != nullptr){
            left->svuota();
        }

        if(right != nullptr){
            right->svuota();
        }
        
        delete this;

    };

};

class BST {
private:
    Node* root;         // radice dell'albero, nullptr se l'albero e' vuoto
    int numNodi;        // numero di chiavi presenti


public:

    BST(){
        root = nullptr;
        numNodi = 0;
    }

    bool isEmpty(){
        if(root == nullptr){
            return true;
        }

        return false;

    }

    int size(){
        return numNodi;
    }

    bool insert(int k){
        if(root == nullptr){
            root = new Node(k);
            return true; 
        }

        Node* dad = nullptr;
        Node* current = root;

        while(current != nullptr) {
            dad = current;
            if(k < current->getData()){
                current = current->getLeft();
            }else if(k > current->getData()){
                current = current->getRight();
            }else{
                return false;
            }
        }

        if(k < dad->getData()){
            dad->setLeft(new Node(k));
        }else{
            dad->setRight(new Node(k));
        }
        
        numNodi++;
        return true;
        
    }

    bool search(int k){
        if(root == nullptr){
            return false;
        }

        Node* current = root;

        while(current != nullptr){
            if(k < current->getData()){
                current = current->getLeft();
            }else if(k > current->getData()){
                current = current->getRight();
            }else{
                return true;
            }
        }

        return false;

    }

    void inOrder(){
        if(root == nullptr){
            return;
        }
        
        root->inOrder();

    }

    int height(){
        if(root == nullptr){
            return 0;
        }
        return root->height();
    }

    int minimo(){
        if(root == nullptr){
            return -1;
        }

        Node* current = root;

        while(current->getLeft() != nullptr){
            current = current->getLeft();
        }

        return current->getData();
    }

    int massimo(){
        if(root == nullptr){
            return -1;
        }

        Node* current = root;

        while(current->getRight() != nullptr){
            current = current->getRight();
        }

        return current->getData();
    }

    void svuota(){
        if(root != nullptr){
            root->svuota();
        }

        root = nullptr;
        numNodi = 0;
    };

    int contaFoglie(){
        if(root == nullptr){
            return 0;
        }

        return root->contaFoglie();
    }

};