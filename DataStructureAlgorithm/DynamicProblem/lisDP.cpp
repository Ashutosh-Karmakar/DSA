#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr = {10,9,2,5,3,7,101,18};
    vector<int> dp(arr.size(),1);
    for(int i=0;i<arr.size();i++){
        for(int j = 0;j<i;j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    for(int i:dp){
        cout << i << endl;
    }
}