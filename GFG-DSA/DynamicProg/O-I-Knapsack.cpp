#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int W = 10;
    int wt[] = {1,3,4,6};
    int v[]  = {20,30,10,50};
    int n = 4;
    vector<vector<int>> dp(n+2,vector<int>(W+2,0));
    dp[0][0] = -1;
    dp[1][0] = 0;
    for(int i=2;i<n+2;i++){
        dp[i][0] = wt[i-2];
    }
    for(int j = 1;j<=W+1;j++){
        dp[0][j] = j-1;
    }

    for(int i=2;i<n+2;i++){
        for(int j=2;j<W+2;j++){
            if(dp[0][j] < dp[i][0]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],v[i-2] + dp[i-1][j-dp[i][0]]);
            }
        }
    }




    for(auto it:dp){
        for(int i:it){
            cout << i << "\t";
        }
        cout << endl;
    }
}