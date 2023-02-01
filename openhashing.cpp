#include <iostream>
#include <bits/stdc++.h>
#define MAX 10
using namespace std;

typedef struct node {
    int data;
    struct node* next;
}NODE;
NODE* bucket[MAX];

//  Japson, James Gabriel H BSIT-2A
//  Open hashing (linked list)

int hashKey(int x){
    return (x % MAX);
}

void init(){
    for (int i = 0; i < MAX; i++){
        bucket[i] = NULL;
    }
}

void insert(int x){
    NODE* newNode = new NODE;
    newNode->data = x;
    newNode->next = NULL;

    int hashVal = hashKey(x);

    if (bucket[hashVal] == NULL)
        bucket[hashVal] = newNode;
    else{
        //  Collision detection
        //  If value has same key, create a linked list at the end of the bucket[hashVal] and add the node
        NODE* tempNode = bucket[hashVal];
        while (tempNode -> next){
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }
}

void del(int x){
    int hashVal = hashKey(x);
    NODE *p, *q;
    p = q = bucket[hashVal];

    while (p != NULL && p->data != x){
        q = p;
        p = p->next;
    }
    if (p == NULL){
        cout << x << " was not found in the hash table" << endl;
        system("pause");
    }
    else{
        if (p == bucket[hashVal])
            bucket[hashVal] = p->next;
        else
            q->next = p->next;
        delete(p);
    }
    
}

void display(){
    cout << "Index\tValue(s)" << endl;
    for (int i = 0; i < MAX; i++){
        NODE* traverse = bucket[i];
        cout << i << "\t";
        while (traverse != NULL){
            cout << traverse->data << " ";
            traverse = traverse->next;
        }
        cout << "NULL"<< endl;
    }
    system("pause");
}
int menu();
int main (){
    init();
    int x;
    while (true){
    switch(menu()){
        case 1:
            system("cls");
            cout << "Enter value of x to be inserted: ";
            cin >> x;
            insert(x);
            break;
        case 2:
            system("cls");
            cout << "Enter value of x to be deleted: ";
            cin >> x;
            del(x);
            break;
        case 3:
            system("cls");
            display();
            break;
        case 4:
            exit(0);
        
        default:
            cout << "Invalid choice" << endl;
            system("pause");
            system("cls");
    }    
  }
    /*
    Test Data
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert (7);
    insert (0);
    insert(7);
    display();
    del(98);
    display();
    */
}

int menu(){
    int x;
    system("cls");
    cout << "--OPEN HASHING--" << endl;
    cout << "Press 1 to INSERT" << endl;
    cout << "Press 2 to DELETE" << endl;
    cout << "Press 3 to DISPLAY" << endl;
    cout << "Press 4 to EXIT" << endl;
    cout << "Enter choice: ";
    cin >> x;

    return x;
}

