#include<iostream>
using namespace std;
void merge(long long arr[],long long start,long long mid,long long end){
    int i = start;
    
    int j = mid+1;
    int p = 0;
    long long *res = new long long int(end-start);
    // int cnt = 0;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            res[p++] = arr[i++];
        }
        else{
            res[p++] = arr[j++];
        }
    }
    while(i<=mid){
        res[p++] = arr[i++];
    }
    while(j<=end){
        res[p++] = arr[j++];
    }
    p = 0;
    for(int i = start ;i<=end;i++){
        arr[i] = res[p++];
    }
}
int ans = 0;
void mergeSort(long long arr[],long long start,long long end){
    // if(start >= end){
    //     return ans;
    // }
    if(start < end){
        int mid = (start + end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,start);
        merge(arr,start,mid,end);
    }
}

int main(){
    long long int arr[] = {2, 4, 1, 3, 5};
    long long int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}