#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    int arr[] = {15,6,5,12,1};
    int N = 5;
    int *li = new int(N);
    for(int i=0;i<N;i++){
        li[i] = 1;
    }
    int i = 1;
    int j = 0;
    while(true){
        if(i==N){
            break;
        }
        if(j==i){
            j=0;
            i++;
        }
        if(arr[i] > arr[j] && li[i] <= li[j] &&
         (arr[j] & arr[i])*2 < (arr[j] | arr[i])    ){
            li[i] = li[j] + 1;
        }
        j++;
    }
    int maxi = -7;
    for(int k = 0;k<N;k++){
        if(maxi < li[k]){
            maxi = li[k];
        }
    }
    cout << maxi << endl;

}