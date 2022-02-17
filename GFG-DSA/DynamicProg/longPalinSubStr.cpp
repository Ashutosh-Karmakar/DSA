#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string s = "abc";
    int N = s.length();
    vector<vector<bool>> dp(N,vector<bool>(N,false));
    for(int i=0;i<N;i++){
        dp[i][i] = true;
    }
    for(int i=0;i<N;i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = true;
        }
    }
    int ans = 1;
    for(int gap=3;gap<=N;gap++){
        for(int i=0,j=gap-1;j<N;i++,j++){
            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1];
            }
            if(dp[i][j]){
                ans = max(ans,j-i+1);
            }
        }
    }
    for(auto it:dp){
        for(bool i:it){
            cout << i << "\t";
        }
        cout << "\n" <<endl;
    }
    cout << ans << endl;
}