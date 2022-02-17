#include<iostream>
using namespace std;
void merge(int arr[],int start,int mid,int end){
    int i=start;
    int j=mid;
    int k=start;
    int *temp = new int[end];
    while(i<mid && j <=end){
        if(arr[i] > arr[j]){
            temp[k++] = arr[j++];
        }
        else{
            temp[k++] = arr[i++];
        }
    }
    while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }
    for(int l = start;l<=end;l++){
        arr[l] = temp[l];
    }

}
void mergeSort(int arr[],int start,int end){
    if(start < end){
        int mid = (start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid+1,end);
    }
}

int main(){
    int arr[] = {9,3,5,1,10,23,2,4,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}