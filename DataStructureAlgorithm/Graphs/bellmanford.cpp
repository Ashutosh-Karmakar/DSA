#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int isNegativeWeightCycle(){
    // Code here
    int n = 3;
    vector<int> dist(n,9999);
    vector<pair<int,int>> *adj = new vector<pair<int,int>>[n];
    adj[0].push_back({-1,1});//{w,n}
    adj[1].push_back({-2,2});
    adj[2].push_back({-3,0});

    for(int l = 0;l<n-1;l++){
        for(int i=0;i<n;i++){
            int u = i;
        }
    }
    
   
    
}
int main(){
    isNegativeWeightCycle();
}