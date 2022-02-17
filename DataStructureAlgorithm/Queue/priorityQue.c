#include<stdio.h>
#include<stdlib.h>
int size = 0;
int arr[100];
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<size && arr[l]>arr[largest]){
        largest = l;
    }
    if(r<size &&  arr[r]>arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(&arr[largest],&arr[i]);
        heapify(largest);
    }

}

void maxHeap(){
    int i;
    for(i=size-1/2;i>=0;i--){
        heapify(i);
    }
}

int deque(){
    int n = arr[0];
    swap(&arr[0],&arr[size-1]);
    size--;
    maxHeap();
    return n;

}

void enque(){
    int num;
    printf("\nEnter the priority into the element:");
    scanf("%d",&num);
    arr[size] = num;
    size++;
    maxHeap();

}
void Display(){
    int i;
    printf("\nThe array is:\t");
    for(i=0;i<size;i++){
        printf("%d",arr[i]);
    } 
}

int main(){
    int i;
    int n;
    int ele;
    printf("Enter the size of the array you want to enter:");
    scanf("%d",&size);
    printf("\nEnter the elements into the array:");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    maxHeap();
    while(1){
        printf("\n____________________________________\n\n");
        printf("1.Enque\n2.Deque\n3.Display\n4.Exit\n");
        printf("____________________________________\n");
        printf(":");
        scanf("%d",&n);
        switch(n){
            case 1:
                enque();
                break;
            case 2:
                ele = deque();
                printf("\nElement Dequed: %d\n",ele);
                break;
            case 3:
                Display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nUnKnown Entry\n");
                break;
        }
    }   

    
}