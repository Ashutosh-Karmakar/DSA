#include<stdio.h>
int main(){
    int arr[] = {7,1,5,3,6,4};
    int N = 6;
    int max = arr[0];
    for(int i=1;i<N;i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    if(max == arr[0])max = 0;
    int max2 = max - arr[0];
    printf("Max: %d\n",max);
    for(int i=1;i<N;i++){
        if(arr[i] == max){
            max = 0;
        }
        else if(arr[i] > max){
            max = arr[i];
        }
        if((max - arr[i])>max2){
            max2 = max-arr[i];
        }
    }
    printf("Max2: %d\n",max2);
}