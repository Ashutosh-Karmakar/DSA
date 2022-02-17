#include<iostream>
#include<math.h>
using namespace std;
int findMissing(int arr[],int diff,int start,int end){
    if(start > end){
        return -1;
    }
    int mid = (start + end)/2;
    if(mid < end && arr[mid+1]-arr[mid] != diff){
        return arr[mid] + diff;
    }
    if(mid > start && arr[mid]-arr[mid-1] != diff){
        return arr[mid-1] + diff;
    }
    if(arr[mid] == (arr[start] + (mid-start)*diff)){
        return findMissing(arr,diff,mid+1,end);
    }
    return findMissing(arr,diff,start,mid-1);
}
int main(){
    int arr[] = {2, 4, 6, 8, 10, 14};
    int n = 7;
    int diff = (arr[n-2] - arr[0])/(n-1);
    cout << diff << endl;
    cout << findMissing(arr,diff,0,n-2);
}