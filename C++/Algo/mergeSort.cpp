#include<iostream>
using namespace std;
int *temp = new int[10];
int merge(int arr[],int start,int mid,int end){
    int i = start;
    int j = mid;
    int k = start;
    int cnt = 0;
    while(i<=mid-1 && j <= end){
        // cout << arr[i] << " " << arr[j] << endl;
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];   
        }
        else{
            temp[k++] = arr[j++];
            cnt = cnt + (mid-i);
        }
    }
    while(i<=mid-1){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }

    for(int l = start;l<= end;l++){
        arr[l] = temp[l];
    }
    return cnt;

}
int mergeSort(int arr[],int start,int end){
    int inv_count = 0;
    if(start < end){
        int mid = (start+end)/2;
        inv_count += mergeSort(arr,start,mid);
        inv_count += mergeSort(arr,mid+1,end);
        inv_count += merge(arr,start,mid+1,end);
    }
    return inv_count;

}
int main(){
    int arr[] = {2, 4, 1, 3, 5};
    int N = 5;
    cout << "Before sorting:" << endl;
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;
    int cnt = mergeSort(arr,0,N-1);
    cout << "After sorting:" << endl;
    for(int i:arr){
        cout << i << " ";
    }
    cout << endl;

    cout << cnt << endl;
}