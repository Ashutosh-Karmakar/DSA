#include<stdio.h>
int mid;
int cnt=0;
int squareROOT(int start,int end,int n){
    cnt++;    
    if(start>=end){
        return 0;
    }
    mid = (start + end)/2;
    if(mid*mid == n){
        return mid;
    }
    if(mid*mid > n){
        return squareROOT(start,mid-1,n);
    }
    else if(mid*mid < n){
        return squareROOT(mid+1,end,n);
    }
}

//     for(int i=1;i<=x/2;i++){
//         if(i*i == x){
//             return 1;
//         }
        
//     }
//     return 0;

// }

int main(){
    int n = 1296;
    printf("%d %d",squareROOT(0,n,n),cnt);
}