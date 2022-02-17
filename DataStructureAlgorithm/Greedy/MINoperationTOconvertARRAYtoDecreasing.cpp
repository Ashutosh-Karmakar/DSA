#include<iostream>
#include<queue>
using namespace std;

int minOperation(int arr[],int n){
    priority_queue<int,vector<int>,greater<int>> pq;
    int opCount = 0;
    for(int i = 0;i<n;i++){
        if(!pq.empty() && pq.top() < arr[i]){
            int diff = abs(pq.top() - arr[i]);
            opCount += diff;
            pq.pop();
        }
        pq.push(arr[i]);
    }
    return opCount;
}


int main(){
    int arr[] = {3, 5, 5, 7, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << minOperation(arr,n);
}