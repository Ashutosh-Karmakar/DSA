#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// vector<long long int> dp(100000,-1);
int solve(int N,int K){
    if(N == 0){
        return 0;
    }
    if(K == 0 || N == K){
        return 1;
    }
    return solve(N-1,K-1)+solve(N-1,K);
 
}
int main(){
    
    cout << solve(0,1) << endl;
}