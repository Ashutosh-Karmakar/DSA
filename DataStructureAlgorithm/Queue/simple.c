#include<stdio.h>
#include <stdlib.h>


#define MAX 10
int front = -1;
int rear = -1;
int que[10];
int isFull(){
    if(rear == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if(front == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(int x){
    if(isFull()){
        printf("The Queue is filled");
    }
    else{
        if(front == -1)
            front = 0;
        que[++rear] = x;
    }
}
int deque(){
    if(isEmpty()){
        print("The que is empty");
    }
    else
        return que[front++];
}
void display(){
    int i;
    for(i=0;i<MAX;i++){
        printf("%d\t",que[i]);
    }
}
int main(){
     int c = 1;
    int ch;
    int x;
    while(c){
        printf("\n1.enque");
        printf("\n2.deque");
        printf("\n3.show elemnts");
        printf("\n4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the value want to enque:");
                scanf("%d",&x);
                enque(x);
                break;
            case 2:
                printf("The element is : %d",deque());
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