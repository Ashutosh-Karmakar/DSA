#include<iostream>
using namespace std;
int n;
void heapify(int arr[],int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if(l <= n && arr[l] > arr[i]){
        largest = l;
    }
    if(r <= n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr,largest);
    }
}

void heapsort(int arr[]){
    for(int i=n/2;i>=0;i--){
        heapify(arr,i);
    }
    int i = n;
    while(n >=0 ){
        int temp = arr[0];
        arr[0] = arr[n];
        arr[n] = temp;
        n--;
        heapify(arr,0);
    }
}

int main(){
    int arr[] = {10,11,2,4,99,10,2,1,9};
    n = sizeof(arr)/sizeof(arr[0])-1;
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
    heapsort(arr);
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
}