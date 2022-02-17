#include<iostream>
#include<stack>
using namespace std;
stack<int> s1;
stack<int> s2;
    
void insert(int arr[],int x){
    s1.push(x);
}
void Enque(int arr[]){
    s2.push(s1.top());
    s1.pop();
}

int main(){
    int arr[5];
    insert(arr,1);
    insert(arr,2);
    insert(arr,3);
    insert(arr,4);
    insert(arr,5);
    Enque(arr);

}