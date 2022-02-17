#include<iostream>
using namespace std;

int partition(int arr[],int start,int end){
    int r = arr[end];//pivot
    int i = start-1;
    for(int j=start;j<end;j++){
        if(arr[j] < r){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[end];
    arr[end] = arr[i+1];
    arr[i+1] = temp;
    return i+1;
}

void quickSort(int arr[],int start,int end){
    if(start < end){
        int p = partition(arr,start,end);
        quickSort(arr,start,p-1);
        quickSort(arr,p+1,end);
    }
}

int main(){
    int arr[] = {10,11,2,4,99,10,2,1,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
    quickSort(arr,0,n-1);
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
}