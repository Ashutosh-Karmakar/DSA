#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    int arr[] = {4, 5, 6, 7, 6};
    int k = 1;
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    int i = 0;
    int diff;
    while(i<n){
        if(arr[i] == x){
            cout << i << endl;
            break;
        }
        diff = abs(x-arr[i]);
        i = i + max(1,(diff/k));
    }
}
