#include<iostream>
using namespace std;

int main(){



    int arr[] = {9,8,4,1,5,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    //bubble sort
    for(int i=0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int res = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = res;
            }
        }
    }

    //selection sort
    int temp ;
    for(int i=0;i<n;i++){
        temp = i;
        for(int j=i+1;j<n;j++){
            if(arr[temp] > arr[j]){
                temp = j;
            }
        }
        if(temp != i){
            int res = arr[temp];
            arr[temp] = arr[i];
            arr[i] = res;
        }
    }

    // insertion sort
    int j,key;
    for(int i=1;i<n;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}