#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int arr[] = {3,10,2,1,20};
    int dist[] = {1,1,1,1,1};
    for(int i=0;i<5;i++){
        for(int j=0;j<i;j++){
            if(arr[i] < arr[j]){
                dist[i] = max(dist[i],dist[j]+1);
            }
        }
    }
    for(int i=0;i<5;i++){
        cout << dist[i] << " ";
    }
}