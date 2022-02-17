#include<iostream>
using namespace std;
#define max 4

int *queue = new int(max);
int front = -1;
int rear = -1;

void enqueue(int n){
    if(rear == max || front == rear+1){
        cout << "Queue is full" << endl;
        return;
    }
    if(front == -1){
        front ++;
    }
    queue[++rear] = n;
}

int dequeue(){
    if(front == -1){
        cout << "Queue is empty" << endl;
        return -1;
    }
    return queue[front++];
    
}
int main(){
    enqueue(20);
    enqueue(10);
    enqueue(10);
    enqueue(10);
    int x = dequeue();
    cout << x << endl;
}