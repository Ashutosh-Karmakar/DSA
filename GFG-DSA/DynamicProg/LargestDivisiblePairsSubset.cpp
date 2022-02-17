#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

/*start 20/20 == 0 so it create a subset of size 1, then 15 i.e 20/15 != 0 so no subset with 20 so its size is 1 
then 10 -- 20/10 == 0 so its subset is 1+2 ans so on to 5 -- 1 + 2 and then 3 -- 1 + 1 
*/


int main(){
    int arr[] = {3,5,10,15,20};
    int N = sizeof(arr)/sizeof(arr[0]);
    vector<int> dp(N,0);
    dp[N-1] = 1;
    for(int i=N-2;i>=0;i--){
        int maxi = 0;
        for(int j=i+1;j<N;j++){
            if(arr[i] % arr[j] == 0 || arr[j] % arr[i] == 0){
                maxi = max(maxi,dp[j]);
            }
        }
        dp[i] = 1+maxi;
    }
    for(int i:dp){
        cout << i << " ";
    }
}