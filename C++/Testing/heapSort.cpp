#include<iostream>
using namespace std;
int n = 0;
void heapify(int arr[],int i){
    int left = i*2+1;
    int right = i*2+2;
    int largest = i;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr,largest);
    }
}
void maxHeap(int arr[]){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i);
    }
}
void heapSort(int arr[]){
    maxHeap(arr);
    for(int i=n-1;i>0;i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        n--;
        heapify(arr,0);
    }
    

}
int main(){
    int arr[] = {9,3,5,1,10,23,2,4,5,1};
    n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int m = n;
    heapSort(arr);
    for(int i=0;i<m;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}