#include<stdio.h>

int sum(int i,int j,int N,int arr[][4]){
    
    if(arr[i][j] == 0) return 0;
    printf("\n%d %d\n",i,j);
    
    if(i==N-1 || j==N-1){
        return 1;
    }
    
    return sum(i,j+1,N,arr) + sum(i+1,j,N,arr);
    
}
int main(){
    int arr[][4] = {{ 1, 1, 1, 1},
		            { 1, 1, 0, 1},
		            { 0, 1, 0, 1},
		            {1, 1, 1, 1}
                  };       
    int N = 4;
    
    printf("\nThe array is :\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    printf("\nThe answer is : %d",sum(0,0,3,arr));

}