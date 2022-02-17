#include<stdio.h>
#include <stdlib.h>

#define MAX 10
int top = -1;
int stack[10];

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(top == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int x){
    if(isFull()){
        printf("The stack is Full");
    }
    else{
        stack[++top] = x;
    }
}
int pop(){
    if(isEmpty()){
        printf("The stack is empty");
    }
    else{
        return stack[top--];
    }
}
void display(){
    int i;
    for(i=0;i<MAX;i++){
        printf("%d\t",stack[i]);
    }
}
int main(){
    int c = 1;
    int ch;
    int x;
    while(c){
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.show elemnts");
        printf("\n4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the value want to push:");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                printf("The element is : %d",pop());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong entry");
                break;
        }
    }
}