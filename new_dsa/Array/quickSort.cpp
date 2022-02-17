//quick sort
#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr,int start,int end){
    // if(start >= end){
    //     return;
    // }
    int pivot = end;
    int i = start-1;
    for(int j=start;j<end;j++){
        if(arr[j] < arr[pivot]){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[end];
    arr[end] = arr[i+1];
    arr[i+1] = temp;
    return i+1; 
}


void quickSort(vector<int> &arr,int start,int end){
    if(start >= end){
        return;
    }
    int pos = partition(arr,start,end);
    quickSort(arr,start,pos-1);
    quickSort(arr,pos+1,end);
}

int main(){
    vector<int> arr = {10,30,40,50,80,90,70};
    for(auto it:arr){
        cout << it << " ";
    }
    quickSort(arr,0,arr.size()-1);
    cout << endl << "After Sorting:" << endl;
    for(auto it:arr){
        cout << it << " ";
    }
    cout << endl;
}

