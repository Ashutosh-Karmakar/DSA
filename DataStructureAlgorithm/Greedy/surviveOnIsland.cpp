#include<iostream>
#include<algorithm>
using namespace std;
int minSurvive(int N,int M ,int S){
    if(N<M){
        return -1;
    }
    int surD = 0;
    int cnt = 0;
    while(true){
        if(S<=0)
            break;
        surD = N/M;
        S = S-surD;
        cnt ++ ;
    }
    return cnt;
}
int main(){
    int N = 20;
    int M = 30;
    int S = 10;
    cout << minSurvive(N,M,S) << endl;
}