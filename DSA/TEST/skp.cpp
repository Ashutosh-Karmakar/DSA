#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<math.h>
#include<stack>

using namespace std;

int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *jump = new int[n];
    jump[0] = 1;

    int cnt = 1;
    int prev = arr[0];
    for(int i=1;i<n;i++){
        if(prev >= arr[i]){
            jump[i] = 1;
        }
        else{
            jump[i] = jump[i-1] + 1;
            
        }
        prev = arr[i];
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += jump[i];
        // cout << jump[i] << " ";
    }

    cout <<sum<< endl;
}