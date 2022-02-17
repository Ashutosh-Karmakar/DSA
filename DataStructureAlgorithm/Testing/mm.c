#include<stdio.h>
int main(){
    int arr[][20] = {{500,2},{100,10},{50,10},{20,10},{5,10}};
    int n = 5;
    int n2 = 2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n2;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    int amt = 1745;
    int temp,i=0,j;
    while(i<n){
        if(amt < arr[i][0]){
            i++;    
            continue;
        }
        temp = amt/arr[i][0];
        if(temp<=arr[i][1]){
            amt = amt - (temp*arr[i][0]);
            printf("%d - %d\n",arr[i][0],temp);
        }
        else{
            amt = amt - (arr[i][1]*arr[i][0]);
            printf("%d - %d\n",arr[i][0],arr[i][1]);
        }
        i++;
    }
    if(amt != 0){
        printf("\nNOT VALID\n");
    }
    else{
        printf("valid");
    }
}