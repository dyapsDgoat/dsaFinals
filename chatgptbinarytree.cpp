#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* newNode(int data){
    node* n = new node();
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void preOrder(node* root){
    if(root){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node* root){
    if(root){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(node* root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main(){
    /*
    Create this binary tree
         1
     2       3
   4   5   6   7
    
    */

    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    cout << "Pre-Order Traversal: ";
    preOrder(root);
    cout << endl;
    cout << "In-Order Traversal: ";
    inOrder(root);
    cout << endl;
    cout << "Post-Order Traversal: ";
    postOrder(root);
    cout << endl;
    return 0;
}
