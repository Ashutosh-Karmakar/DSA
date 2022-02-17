#include<stdio.h>
int size = 0;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[] , int i){
    if(size==1){
        printf("The array has only one element");
    }
    else{
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if(l < size && arr[l] > arr[largest]){
            largest = l;
        }
        if(r < size && arr[r] > arr[largest]){
            largest = r;
        }
        if(largest != i){
            swap(&arr[i],&arr[largest]);
            heapify(arr,largest);
        }
    }
}
void insert(int arr[]){
    int n;
    printf("\nEnter the value want to insert:");
    scanf("%d",&n);
    arr[size] = n;
    size++;
    for(int i=size/2-1 ; i>=0 ; i--){
        heapify(arr,i);
    }
}
void delete(int arr[]){
    int i;
    int num;
    printf("\nEnter the value want to delete:");
    scanf("%d",&num);

    for(i=0;i<size;i++){
        if(arr[i] == num){
            swap(&arr[i],&arr[size-1]);
            break;
        }
    }
    size--;
    for(i=size/2-1;i>=0;i--){
        heapify(arr,i);
    }

}
int main(){
    int arr[10];
    printf("Enter the size of the arr:");
    scanf("%d",&size);
    printf("%d",size);
    printf("Enter the elements in the arr:\n");
    for(int i=0 ; i<size ; i++){
        scanf("%d",&arr[i]);
    }
    for(int j=0 ; j<size ; j++){
        printf("%d\t",arr[j]);   
    }
    for(int i=size/2-1 ; i>=0 ; i--){
        heapify(arr,i);
    }   
    printf("\n");
    for(int j=0 ; j<size ; j++){
        printf("%d\t",arr[j]);
    }
        insert(arr);
        for(int j=0 ; j<size ; j++){
            printf("%d\t",arr[j]);
        }
    delete(arr);
    for(int j=0 ; j<size ; j++){
        printf("%d\t",arr[j]);
    }
}