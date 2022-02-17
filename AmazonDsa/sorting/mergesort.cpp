#include<iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end){
    int l = start;
    int j = mid + 1;
    int *res = new int(end-start+1);
    int k = 0;
    while(l <= mid && j <= end){
        if(arr[l] < arr[j]){
            res[k++] = arr[l++];
        }
        else{
            res[k++] = arr[j++];
        }
    }
    while(l <= mid){
        res[k++] = arr[l++];
    }
    while(j <= end){
        res[k++] = arr[j++];
    }
    k = 0;
    for(int i=start;i<=end;i++){
        arr[i] = res[k++];
    }
}
void mergeSort(int arr[],int start,int end){
    if(start < end){
        int mid = (start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main(){
    int arr[] = {10,11,2,4,99,10,2,1,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
    mergeSort(arr,0,n-1);
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
}