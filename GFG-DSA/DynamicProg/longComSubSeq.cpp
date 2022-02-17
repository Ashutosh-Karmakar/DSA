#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> dp (10000,vector<int>(10000,-1));
int solve(string s1,string s2,int i,int j){
    if(i>= s1.length() || j>=s2.length()){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s1[i] == s2[j]){
        return dp[i][j] = 1+solve(s1,s2,i+1,j+1);
    }
    return dp[i][j] =  max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
}

int main(){
    string s1 = "wanda";
    string s2 = "wakanda";
    cout << solve(s1,s2,0,0) << endl;

}