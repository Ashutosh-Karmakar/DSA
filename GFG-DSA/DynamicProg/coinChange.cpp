#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
// vector<vector<int>> dp (10000,vector<int>(10000,-1));

int solve(int N,int coins[],int index){
    if(index == -1 && N > 0){
        return 0;
    }
    if(N == 0){
        return 1;
    }
    if(N<0){
        return 0;
    }
    return solve(N-coins[index],coins,index) + solve(N,coins,index-1);
}

int main(){
    int N = 10;
    int coins[] = {2, 5, 3, 6};
    cout << solve(N,coins,4) << endl;

}