#include<iostream>
using namespace std;
int N;
int arr[] = {1,3,6,5,9,8};

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Heapify(int arr[],int n,int i){
    int largest = i;
    // cout << i << endl;
    int l = i*2 + 1;
    int r = i*2 + 2;
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]){
        largest = r;    
    }
    if(largest != i){
        swap(&arr[largest],&arr[i]);
        Heapify(arr,n,largest);
    }
}

void maxHeap(int arr[]){
    for(int i = (N/2)-1;i>=0;i--){
        Heapify(arr,N,i);
    }
}
int deleteTop(int arr[]){
    int temp = arr[0];
    arr[0] = arr[N-1];
    N--;
    for(int i=(N/2)-1;i>=0;i--){
        Heapify(arr,N,i);
    }
    return temp;
}
void heapSort(int arr[]){
    
    for(int i=N-1;i>=0;i--){
        swap(&arr[i],&arr[0]);
        Heapify(arr,i,0);
    }
}

int main(){
    N = 6;

    cout << "The array is : " << endl;
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    maxHeap(arr);
    cout << "The array is after maxheap() : " << endl;
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // cout << "The top element is :" << endl;
    // cout << deleteTop(arr) << endl;
    heapSort(arr);

    cout << "The array is after maxheap() : " << endl;
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}