#include<iostream>
using namespace std;
int binSearch(int arr[],int start,int end ,int x){
    if(start >= end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid] == x){
        return mid;
    }
    else if(arr[mid] > x){
        return binSearch(arr,start,mid-1,x);
    }
    return binSearch(arr,mid+1,end,x);
    
}
int 
main(){
    int arr[] = {2,3,4,10,40};
    int n = 5;
    int x = 11;
    cout << binSearch(arr,0,n-1,x) << endl;

}