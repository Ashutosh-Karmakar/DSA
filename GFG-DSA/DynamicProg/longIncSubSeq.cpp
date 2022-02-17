#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> dp(10000,vector<int>(10000,-1));
int solve(int arr[],int n,int prev,int index){
    if(index >= n){
        return 0;
    }
    if(prev == -1){
        return dp[index][prev] = max(1+solve(arr,n,index,index+1),solve(arr,n,prev,index+1));
    }
    if(dp[index][prev] != -1){
        return dp[index][prev];
    }
    if(arr[prev] >= arr[index]){
        return dp[index][prev] = solve(arr,n,index,index+1);
    }
    return dp[index][prev] = max(1+solve(arr,n,index,index+1),solve(arr,n,prev,index+1));
}
int main(){
    int arr[] = {10,9,6,11,8,13,14,12,16};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << solve(arr,n,-1,0) << endl;
}