#include<iostream>
using namespace std;
int top = -1;
int maxi = 4;
int *stack = new int(maxi);
void push(int data){
    if(top >= maxi){
        cout << "The stack is full" << endl;
        return;
    }
    stack[++top] = data;
}
int pop(){
    if(top == -1){
        cout << "Stack Is Empty" << endl;
        return -1;
    }
    return stack[top--];
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    cout << pop() << endl;
}