#include<iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end){
    int i = start;
    int j = mid+1;
    int *res = new int(end-start+1);
    int k = 0;
    while(i<=mid && j <= end){
        if(arr[i] < arr[j]){
            res[k++] = arr[i++];
        }
        else{
            res[k++] = arr[j++];
        }
    }
    while(i<=mid){
        res[k++] = arr[i++];
    }
    while(j<=end){
        res[k++] = arr[j++];
    }
    k = 0;
    for(i=start;i<=end;i++){
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
    return ;
}
int main(){
    int arr[] = {6,23,6,2,2,3,13234,6,542,32,4,564,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << n << endl;
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
    mergeSort(arr,0,n-1);
    for(int i:arr){
        cout << i << " ";
    }

}