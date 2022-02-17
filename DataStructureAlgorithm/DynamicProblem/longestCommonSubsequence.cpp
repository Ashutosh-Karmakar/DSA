#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N1,N2;
vector<vector<int>> dp(1000,vector<int>(1000,-1));
int lcs(string s1,string s2,int i,int j){
    if(i >= N1 || i>=N2) return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i] == s2[j]){
        return dp[i][j] = 1+lcs(s1,s2,i+1,j+1);
    }
    return dp[i][j] = max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
    
}


int main(){
    string s1 = "wanda";
    string s2 = "wakanda";
    N1 = s1.length();
    N2 = s2.length();

    cout << lcs(s1,s2,0,0);
}