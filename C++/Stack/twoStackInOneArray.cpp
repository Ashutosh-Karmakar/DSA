//implementing two stacks using only one array
#include<iostream>
#define max 10
using namespace std;

int top1 = -1;
int top2 = max;
int arr[max];

bool Full(){
    if(top1 == top2 - 1){
        return true;
    }
    return false;
}
bool Empty1(){
    if(top1 == -1)
        return true;
    return false;
}
bool Empty2(){
    if(top2 == max+1){
        return true;
    }
    return false;
}

void insert1(int x){
    if(Full()){
        cout << "array is full sorry" << endl;
        return;
    }
    arr[++top1] = x;
}
void insert2(int x){
    if(Full()){
        cout << "array is full sorry" << endl;
        return;
    }
    arr[--top2] = x;
}
int pop1(){
    if(Empty1()){
        cout << "array is empty sorry" << endl;
        return -1;
    }
    return arr[top1--];
}
int pop2(){
    if(Empty2()){
        cout << "array is empty sorry" << endl;
        return -1;
    }
    return arr[top2++];
}

void print(){
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    insert1(10);
    insert1(20);
    insert1(30);
    insert1(40);
    
    insert2(1);
    insert2(2);
    insert2(3);    
    insert2(4);    
    insert2(5);    
    insert2(6);
    cout << pop1() << endl;
    cout << pop1() << endl;
    cout << pop2() << endl;
    cout << pop2() << endl;    
    cout << pop1() << endl;    
    cout << pop1() << endl;    
    cout << pop1() << endl;    

    print();
}

