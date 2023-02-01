#include <iostream>
using namespace std;
//  QUEUE = First In First Out 
//  Insert at the last node
//  Remove at the front node
struct node{
    int data;
    node* link;
};
    node* front = NULL;
    node* rear = NULL;
void enqueue(int value){
    //  Basically just insert node at end

    //  Create a new node
    //  The new node value is the parameter
    //  Since this would be the end node, the link would be NULL
    node* ptr  = new node();
    ptr->data = value;
    ptr->link = NULL;

    //  If linked list is empty, the new node becomes the front (head) and rear of the list
    if (front == NULL){
        front = ptr;
        rear = ptr;
    }
    else{
        //  If the linked list is not empty, the new node was link using the rear
        //  The pointer of rear points to the next node 
        //  Then the node becomes the rear
        rear->link = ptr;
        rear = ptr;
    }
}

void dequeue(){
    //  Checks if linked list is empty
    if (front == NULL & rear == NULL){
        cout << "Linked list is empty!" << endl;
    }
    if (front == rear){
        //  If there is only one node, free the node then makes the front and rear to NULL (Means that there is no node)
        free(front);
        front = rear = NULL;
    }
    else{
        //  Create a node and assign the front part of an existing nodes
        //  Then the existing nodes front moves to the second node
        //  Then free the created node
        //  To avoid segmentation fault 
        node*ptr = front;
        front = front->link;
        free(ptr);
    }

}
void showFront(){
    //  Show the first inserted node
    if(front == NULL && rear == NULL){
        cout << "Linked list is empty!" << endl;
    }
    else{
        cout << "Front data is " << front->data << endl;
    }
}
void showLinkedList(){
    
    if(front == NULL && rear == NULL){
        cout << "Linked list is empty!" << endl;
        return;
    }else{ 
    // Create a node to traverse the list
    node* traverse = front;
    while (traverse != NULL){
        cout << traverse->data << endl;
        traverse = traverse->link; 
    }
    }
}

int main(){
    //  enqueue(1);
    enqueue(3);
    enqueue(10);
    showLinkedList();
    dequeue();
    //showFront();
    showLinkedList();
}