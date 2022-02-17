#include<iostream>
#include<string>
#include<vector>
using namespace std;


void function(string s){
    int mX=0;
    int mY=0;
    int n = s.length();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
    }
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
        }
    }
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j=i+k-1;
            if(dp[i+1][j-1] == 1 && s[i] == s[j]){
                dp[i][j] = 1;
                if(j-i > mY-mX){
                    mX = i;
                    mY = j;
                }
            }
        }
    }
    for(auto i:dp){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << mX << " " << mY << endl;

}
int main(){
    string s = "aaaabbaa";
    function(s);
}