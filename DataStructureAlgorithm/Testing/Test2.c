// Maximum rectangle formed from a bar chart


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *stack;
int top = -1;
int seek(){
    return stack[top];
}

void pop(){
    top--;
}

void push(int x){
    stack[++top] = x;
}

int main(){
    int h_count = 5;
    int h[] = {1,2,3,4,5}; 
    int l[20];
    int r[20];
    stack = (int *)malloc(h_count * sizeof(int));
    for(int i=0;i<h_count;i++){
        for(int j=top;j>=0;j--){
            if(h[stack[j]] >= h[i]){
                pop();
            }
            else{
                break;
            }
        }
        if(top == -1){
            l[i] = 0;
        }
        else{
            l[i] = seek() + 1;
        }
        push(i);
    }
    for(int i=0;i<h_count;i++){
        printf("%d\t",h[i]);
    }
    printf("\n");
    for(int i=0;i<h_count;i++){
        printf("%d\t",l[i]);
    }

    top = -1;
    for(int i=h_count-1;i>=0;i--){
        for(int j=top;j>=0;j--){
            if(h[stack[j]] >= h[i]){
                pop();
            }
            else{
                break;
            }
        }
        if(top == -1){
            r[i] = h_count - 1;
        }
        else{
            r[i] = seek() - 1;
        }
        push(i);
    }
    printf("\n");
    for(int i=0;i<h_count;i++){
        printf("%d\t",r[i]);
    }

    int max = h[0] * (r[0] - l[0]);
    for(int i=1;i<h_count;i++){
        if(max < h[i]*(r[i] - l[i] + 1)){
            max = h[i]*(r[i] - l[i] + 1);
        }
    }
    printf("\n\n%d",max);
}