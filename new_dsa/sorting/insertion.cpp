#include<iostream>
using namespace std;

void insertion(int arr[],int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int key = arr[i];
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {4,2,4,9,10,1,0};
    int n = 7;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    insertion(arr,n);
    
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

}