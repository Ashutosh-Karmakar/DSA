#include<iostream>
using namespace std;
int findUnique1(int arr[],int n){
    int xori = 0;
    for(int i = 0;i<n;i++){
        xori = (xori ^ arr[i]);
    }
    return xori;
}
void findUniqueTwoElement(int arr[],int n){
    int xorSum = 0;
    for(int i=0;i<n;i++){
        xorSum = (xorSum^arr[i]);
    }
    cout << xorSum << endl;
    int pos = 0;
    while((xorSum & (1<<pos)) == 0){
        pos++;
    }
    cout << pos << endl;
    int newXor = 0;
    for(int i = 0;i<n;i++){
        if((arr[i] & (1<<pos)) != 0){
            newXor = newXor ^ arr[i];
        }
    }
    cout << newXor << " , " << (xorSum ^ newXor) << endl;
}
int main(){
    int arr[] = {1,2,3,4,1,2,3};
    int n = 7;
    cout << "Uni1: " << findUnique1(arr,n) << endl;
    cout << "Unique Two elements" << endl;
    int arr2[] = {1,2,3,5,1,3,4,4};
    int n2 = 8;
    findUniqueTwoElement(arr2,n2);
}