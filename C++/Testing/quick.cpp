#include<iostream>
using namespace std;


int partition(int arr[],int start,int end){
    int key = arr[end];
    int i = start-1;
    for(int j=start;j<end;j++){
        if(arr[j] < key){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return i+1;
}

void quickSort(int arr[],int start,int end){
    if(start < end){
        int pos = partition(arr,start,end);
        quickSort(arr,start,pos-1);
        quickSort(arr,pos+1,end);
    }
}


int main(){
    int arr[] = {9,3,5,1,10,23,2,4,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr,0,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}