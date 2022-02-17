#include<iostream>
using namespace std;
#define maxi 4
int *stack = new int(maxi);
int top = -1;

void push(int n){
    if(top < maxi){
        stack[++top] = n;
    }
    else{
        cout << "Stack OverFlow" << endl;
    }
}

int pop(){
    if(top > -1){
        return stack[top--];
    }
    cout << "Stack Empty" << endl;
    return -1;
}
void printstack(){
    for(int i=top;i>=0;i--){
        cout << stack[i] << " ";
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    // pop();
    printstack();
}