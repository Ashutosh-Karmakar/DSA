#include<iostream>
#include<vector>
using namespace std;
int lexi(int arr[],int n,int k){
    int i = 0;
    while(k>0 && i<n){
        int mini = i;
        for(int j = i+1;j<n;j++){
            if(j-i > k){
                break;
            }
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        for(int j = mini;j>i;j--){
            int temp = arr[j];
            arr[j] =arr[j-1];
            arr[j-1] = temp;
            k--;
            
        }
        i++;
        cout << k << endl;
    }
    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
    return 0;
    
}
int main(){
    int arr[] = {7, 6, 9, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    lexi(arr,n,5);
}