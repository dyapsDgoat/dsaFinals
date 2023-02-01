#include <iostream>
#include <stdlib.h>
#define MAX 5
using namespace std;

// STACKS - LAST-IN FIRST-OUT (LIFO)
// Allows insertion and deletion at one point called the top of the stack
// Add back, delete back

class Stack {
    private:
        int S[MAX]; // Array to store the stack
        int top;    // Marker to keep track of the top of the stack
    public:
        Stack() { top = -1; }  // Constructor to initialize the stack
        bool isFull() { return top == MAX-1; }  // Check if the stack is full
        bool isEmpty() { return top == -1; }   // Check if the stack is empty
        void push(int x);   // Function to add an element to the stack
        int pop();         // Function to remove an element from the stack
        void display();    // Function to display the elements of the stack
};

void Stack::push(int x) {
    if (isFull()) {
        cout << "Stack overflow." << endl;
        return;
    }
    S[++top] = x;  // Add the element to the top of the stack
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return S[top--]; // Remove the top element from the stack
}

void Stack::display() {
    cout << "The stack contains: ";
    for (int i = 0; i <= top; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack s;
    s.push(9);    // Add 9 to the stack
    s.push(2);    // Add 2 to the stack
    s.push(5);    // Add 5 to the stack
    s.push(12);   // Add 12 to the stack
    s.push(13);   // Add 13 to the stack
    s.display();  // Display the elements of the stack
    s.pop();      // Remove the top element (13) from the stack
    s.display();  // Display the elements of the stack
    return 0;
}
