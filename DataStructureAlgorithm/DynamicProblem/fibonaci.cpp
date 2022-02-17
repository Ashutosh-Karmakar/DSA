#include<iostream>
#include<vector>
using namespace std;
int M;
vector<int> dp(INT_MAX,-1);
int fib(int N,vector<int> &dp){
    if(N<=1){
        return N;
    }
    if(dp[N]!=-1){
        return dp[N];
    }
    else{
        return dp[N] = fib(N-1,dp) + fib(N-2,dp);
    }
}

    
int main(){
    M = 656;
    cout << fib(M,dp) << endl;
}