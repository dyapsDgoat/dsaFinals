#include <iostream>
using namespace std;

//  Stacks = Last In First Out (LIFO)
struct node{
    int data;
    node* link;
};

node* head = NULL;

void insertFront(int value){
    node* ptr = new node();
    ptr->data = value;
    ptr->link = head;

    head = ptr;
}

void showLinkedList (){
    node* traverse = head;
    while (traverse!=NULL){
        cout << traverse->data << endl;
        traverse = traverse->link;
    }
}

void popLastNode(){
    //  Pop the head node
    //  head->node->node->node
    if (head == NULL){
        cout << "Stack is empty!" << endl;
    }
    else{
        //  The newly created node becomes the list
        //  Then the head of the list become the second node, then delete the first node (old list)
        //  Can we just set the head = head->link? (Yes hehe, kaso sayang memory baka mabaliw system mo hehe)
        node* ptr = head;
        head = head->link;
        delete(ptr);
    }

}

int main(){
    insertFront(1);
    insertFront(5);
    insertFront(2);
     showLinkedList();
    //  Linked list = 2-5-1
    popLastNode();
    //  Linked list = 5-1
    showLinkedList();
    



}