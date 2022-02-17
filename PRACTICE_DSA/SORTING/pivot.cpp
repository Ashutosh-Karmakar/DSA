#include<iostream>
#include<vector>
using namespace std;
int findPivot(int arr[],int start,int end){
    if(start > end){
        return -1;
    }
    if(start == end){
        return start;
    }
    int mid = (start+end)/2;
    if(mid < end && arr[mid] > arr[mid+1]){
        return mid;
    }
    if(mid>start && arr[mid] < arr[mid-1]){
        return mid-1;
    }
    if(arr[mid] >= arr[start]){
        return findPivot(arr,mid+1,end);
    }
    return findPivot(arr,start,mid-1);
}
int main(){
    int arr[] = {6,7,8,0,1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findPivot(arr,0,n-1) << endl;
}