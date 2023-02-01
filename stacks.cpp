#include <iostream>
#include <stdlib.h>
#define MAX 5

using namespace std;
//  STACKS - LAST-IN FIRST-OUT (LIFO)
//  Allows insertion and deletion at one point called the top of the stack
//  Add back, delete back

typedef struct stack{
    //  STACKS array of structures implementation
    int S[MAX]; //  Array in a struct
    int top;    //  Marker
}STACK;
STACK S; 

void stackMakeNull(){
    S.top = MAX;
}

int stackIsFull(){
    return (S.top==0);
}

int stackIsEmpty(){
    return(S.top==MAX);
}

void stackPush(int x){
    if (stackIsFull()){
        cout << "Stack overflow." << endl;
        getchar();
    }
    else{
        S.top--;
        S.S[S.top] = x;
    }
}

void stackPop(){
    if (stackIsEmpty()){
        cout << "Stack is empty" << endl;
    }
    else
        S.top++;
}

void stackDisplay(){
    int i, j = 1;
    system("cls");

    cout << "The stack contains" << endl;
    //  The initialization of
    for (i = S.top; i<MAX; i++){
        cout << j++ << " " << S.S[i] << endl;
        //  getchar();
    }
}

void stackMenu(){
    stackMakeNull();
    stackPush(9);   //  array S = [0,0,0,0,9]
    stackPush(2);   //  array S = [0,0,0,2,9]
    stackPush(5);   //  array S = [0,0,5,2,9]
    stackPush(12);  //  array S = [0,12,5,2,9]
    stackPush(13);  //  array S = [13,12,5,2,9]
    stackDisplay();
    stackPop();     //  array S = [0,12,5,2,9]
    stackDisplay();
}

int main (){
    stackMenu();


}