#include<stdio.h>
int main(){
    int arr[] = {9,20,16,6,5,9,21,8,14,5,12,21,9};
    int N = 13;
    int diff[20];
    diff[0] = arr[0];
    for(int i=1;i<N;i++){
            diff[i] = arr[i] - arr[i-1];
            if(diff[i] < 0) diff[i] = diff[i]*-1;
    }
    printf("\n");
    int max = 0;
    for(int i=0;i<N;i++){
        if(diff[max] <diff[i] ){
            max = i;
        }
    }
    printf("\n%d - %d = %d",arr[max-1],arr[max],diff[max]);
    }