#include <iostream>
using namespace std;
//  Japson, James Gabriel H. BSIT-2A
//  Write the Binary Tree Traversals (Pre order, In-order, Post-order) using pointer implementation (C or C++)

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}NODE;

NODE* newNode(int data){
    NODE* node = new NODE();
    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return node;
}

void display(NODE* root){

    cout << "\t " <<root->data << endl;
    cout << "     " << root->left->data << "       " << root->right->data<< endl;
    cout << "   "<<root->left->left->data << "   " << root->left->right->data << "   " << root->right->left->data << "   " << root->right->right->data<< endl;
    
    system("pause");
}   

void preorder(NODE* root){
    if (root != NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right); 
    }
}

void inorder (NODE* root){
    if (root != NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(NODE* root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main (){
    /*
    Create this binary tree
         1
     2       3
   4   5   6   7
    
    */

    NODE* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    cout << "\tBINARY TREE" << endl;
    display(root);

    cout << "PREORDER TRAVERSAL" << endl;
    preorder(root);
    
    cout << "\nINORDER TRAVERSAL" << endl;
    inorder(root);

    cout << "\nPOSTORDER TRAVERSAL" << endl;
    postorder(root);
    cout << "\n";
    system("pause");
}