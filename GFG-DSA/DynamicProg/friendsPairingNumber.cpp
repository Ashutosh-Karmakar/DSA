#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int solve(int n,vector<int> &dp){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n-1,dp) + (n-1)*solve(n-2,dp); //either we make singles i.e n-1 or we pair n-1th 
        //with n-2 person i.e we add all the permutations i.e n-1 * solve(n-2);
    }

int main(){
    int N = 3;
    vector<int> dp(N+1,-1);

    cout << solve(N,dp) << endl;
}