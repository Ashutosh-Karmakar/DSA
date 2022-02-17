// TC: O(N log(N))
// heapify: O(log N);
// In-Place Algo
// Not Stable but can be made stable
#include<iostream>
using namespace std;

void heapify(int arr[],int i,int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest;
    if(l<n && arr[l] > arr[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r<n && arr[largest] < arr[r]){
        largest = r;
    }
    if(largest != i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr,largest,n);
    }

}
void maxHeap(int arr[],int n){
    for(int i =(n/2)-1;i>=0;i--){
        heapify(arr,i,n);
    }
}
void heapSort(int arr[],int n){
    maxHeap(arr,n);
    for(int i =n-1; i>=0;i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        n = n-1;
        cout << n << endl;
        maxHeap(arr,n);
    }
}

int main(){
    int arr[] = {8,2,3,9,10,11,34};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
    heapSort(arr,n);
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
}