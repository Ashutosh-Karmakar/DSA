#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long int> dp(100000,-1);
long long int solve(int N){
    if(N<=1) return 1;
    long long int result = 0;
    if(dp[N] != -1){
        return dp[N];
    }
    else{
        for(int i=0;i<N;i++){
            result = result+(solve(i)*solve(N-i-1));
        }
        return dp[N] = result;
    }
}
int main(){
    
    cout << solve(9) << endl;
}