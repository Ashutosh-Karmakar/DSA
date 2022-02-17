#include<iostream>
using namespace std;

void bubble(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int arr[] = {4,2,4,9,10,1,0};
    int n = 7;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    bubble(arr,n);
    
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}