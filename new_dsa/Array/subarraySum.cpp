#include<iostream>
#include<vector>
using namespace std;

void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int merge(int arr[],int start,int end,int mid){
    int i=start;
    int j = mid+1;
    int *res = new int(start-end);
    int k = 0;
    int cnt = 0;
    while(i<=mid && j <= end){
        if(arr[i] < arr[j]){
            res[k++] = arr[i++];
        }
        else{
            cnt ++;
            res[k++] = arr[j++];
        }
    }
    while(i<=mid){
        res[k++] = arr[i++];
    }
    while(j<=end){
        res[k++] = arr[j++];
        cnt ++;
    }
    k = 0;
    for(int i=start;i<=end;i++){
        arr[i] = res[k++];
    }
    return cnt;
}

int mergeSort(int arr[],int start,int end){
    int cnt = 0;
    if(start < end){
        int mid = (start+end)/2;
        cnt += mergeSort(arr,start,mid);
        cnt += mergeSort(arr,mid+1,end);
        cnt += merge(arr,start,end,mid);
    }
    return cnt;
}

int main(){
    int arr[] = {15,10,11,8};
    int n = 4;
    int cnt = mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n" << cnt << endl;

}