#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool solve(int arr[],int sum,int index,int N,vector<vector<bool>> &dp){
    if(index == N && sum > 0){
        return false;
    }
    if(sum < 0){
        return false;
    }
    if(sum == 0){
        return true;
    }
    if(dp[sum][N]){
        return dp[sum][N];
    }
    return dp[sum][N] = solve(arr,sum,index+1,N,dp) || solve(arr,sum-arr[index],index+1,N,dp);
}

int main(){
    int sum= 9;
    int arr[] = {3, 34, 4, 12, 5, 2};
    int N = sizeof(arr)/sizeof(arr[0]);
    vector<vector<bool>> dp(sum+1,vector<bool>(N,false));
    cout << solve(arr,sum,0,N,dp) << endl;
    
}