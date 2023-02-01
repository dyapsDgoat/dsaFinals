#include <iostream>
using namespace std;

struct node {
    int data;
    node* link;
};

node* head = NULL;

void insertEnd(int data){
    //  Create a new node then set the data of the node to the parameter
    node* ptr = new node();
    ptr->data = data;
    //  Since we are inserting a node to the end, the link value should be NULL so that a new node can be assigned to this pointer
    ptr->link = NULL;

    if (head==NULL){
        //  If linkedlist is empty, the newly created node will be the head 
        head = ptr;
    }
    else{
        //  Traverse
        //  Basically the temp node checks each node by using the head then when the last node (temp->link)
        //  is found, the newly created ptr node becomes the last node using the temp->link
        node* temp = head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = ptr;
    }
}

void insertFront (int data){
    node* temp = new node();
    temp ->data = data;
    temp ->link = head;    
    
    head = temp;
}

void showLinkedList (){
    node* traverse = head;
    while (traverse!=NULL){
        cout << traverse->data << endl;
        traverse = traverse->link;
    }
}

void ytSortLinkedList(){
    // https://www.youtube.com/watch?v=pdMPvMM12G0
    node *end, *p, *q;
    int temp;
    //  The first loop means that the while the end node is equal to NULL (last node)
    //  And the end is not the second node (Since you only need to compare n-1 , n = nodes)
    //  The end decrements until it reaches the first node (head), basically just --
    //  Bubble sort by swapping node data.
    for(end=NULL; end!=head->link; end=p){
        //  the p is the head
        //  while the second node is not equal to the end, the loop increment using the p = p-> link
        for (p=head; p->link!=end; p=p->link){
            //  The q will become the adjacent node of the p and compares the value in the if statement below
            q = p->link;
            if (p->data > q->data){
            //  The temp data becomes the higher value
            //  Then the p (higher value) will become the lower value
            //  Then the q (lower value) will become the higher value, using the temp value 
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

int main(){
    insertFront(3);
    insertFront(2);
    insertFront(1);
    ytSortLinkedList();
    showLinkedList();
}   