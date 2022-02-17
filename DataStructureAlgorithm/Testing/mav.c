#include<stdio.h>
int main(){
    int b = 6478434;
    int max =0;
    int temp;
    while(b >= 100){
        temp = b % 1000;
        if(max < temp){
            max = temp;
        }
        b = b/10;

    }
    printf("%d",max);
}

