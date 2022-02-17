#include<iostream>
using namespace std;

int binnarySearch(int arr[],int start,int end,int f){
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == f){
            return mid;
        }
        if(arr[mid] < f){
            start = mid+1;
        }
        else if(arr[mid] > f){
            end = mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << binnarySearch(arr,0,n-1,11) << endl;
}