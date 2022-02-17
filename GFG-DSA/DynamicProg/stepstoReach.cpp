#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int solve(int N,int step){
    if(N<step){
        return 0;
    }
    if(N==step){
        return 1;
    }
    return solve(N,step+1) + solve(N,step+2);
}

int main(){
    int N = 10;
    cout << solve(N,0) << endl;
}