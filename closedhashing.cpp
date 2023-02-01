#include <iostream>
#include <bits/stdc++.h>
#define MAX 10
using namespace std;

//  Japson, James Gabriel H BSIT-2A
//  Closed hashing using linear probing as collision resolution technique

int bucket[MAX];

int hashKey(int x){
    return (x % MAX);
}
void insert(int x){
    int hashVal = hashKey(x);

    if (bucket[hashVal] == -1)
        bucket[hashVal] = x;
    else{
        /*
        //  Insertion using Quadratic probing
        for (int i = 0; i < MAX; i++){
            int newHashVal = (hashVal + i * i) % MAX;
            if (bucket[newHashVal] == -1){
                bucket[newHashVal] = x;
                break;
            }
        }
        */
       //  Insertion using linear probing
       for (int i = 0; i < MAX; i++){
            hashVal = (hashVal + 1) % MAX;

            if (bucket[hashVal] == -1){
                bucket[hashVal] = x;
                break;
            }
            if (i == MAX-1){
                system("cls");
                cout << "Hash table is full, can not add value." << endl;
                system("pause");
            }
       }
    }
}
void del(int x){
    int hashVal = hashKey(x);

    if (bucket[hashVal] == x)
        bucket[hashVal] = -1;
    else{
        for (int i = 0; i < MAX; i++){
            hashVal = (hashVal + 1) % MAX;

            if (bucket[hashVal] == x){
                bucket[hashVal] = -1;
                break;
            }
            if (i == MAX - 1){
                system("cls");
                cout << x << "is not on the hash table" << endl;
                system("pause");

            }
                
        }
    }
}
void display(){
    cout << "Index\tValue" << endl;
    for (int i = 0; i < MAX; i++){
        cout << i << "\t" << bucket[i] << endl;
    }
    system("pause");
}
void init(){
    // -1 represents that the array element is not present
    for (int i = 0; i < MAX; i++){
        bucket[i] = -1;
    }
}

int menu();

int main (){
    int x;
    init();
   
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

     //  Block comment the switch statement and uncomment the following code to test 
    /*
    insert(23);
    insert(45);
    insert(78);
    insert(13);
    insert(26);
    insert(94);
    insert(57);
    insert(5);
    insert(49);
    insert(62);

    //  Display the hash table
    display();

    //  Delete an element
    //  del(23);
    //  Display the hash table
    //  display();
    */
}

int menu(){
    int x;
    system("cls");
    cout << "--CLOSED HASHING--" << endl;
    cout << "Press 1 to INSERT" << endl;
    cout << "Press 2 to DELETE" << endl;
    cout << "Press 3 to DISPLAY" << endl;
    cout << "Press 4 to EXIT" << endl;
    cout << "Enter choice: ";
    cin >> x;

    return x;
}