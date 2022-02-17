#include<iostream>
#include<vector>

using namespace std;

int main(){
    int arr[] = {10,5,8,7,9,14,15,12,90,100};
    int N = 10;
    int k = 4;
    int maxk = arr[0];     // max of k
    int maxk2 = arr[1];   // max of k-1
    for(int i=1;i<k;i++){
        if(maxk < arr[i]){
            maxk = arr[i]; 
        }
    }
    for(int i=2;i<k;i++){
        if(maxk2 < arr[i]){   
            maxk2 = arr[i]; 
        }
    }

    for(int i=1;i<=N-k+1 ;i++){
        cout << maxk << endl;
        if(maxk == arr[i-1]){               // if max is excaping
            if(maxk2 < arr[i+k-1]){
                maxk = arr[i+k-1];
                maxk2 = arr[i+k-1];
            }
            else{
                maxk = maxk2;
            }
        }
        else{                              //if max is less now from the new
            if(maxk < arr[i+k-1]){
                maxk = arr[i+k-1];
                maxk2 = arr[i+k-1];
            }
        }
    }
}