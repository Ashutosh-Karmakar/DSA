#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a[] = {7,5,4,2,9,3};
    int b[] = {4,9,6,8,7,1};
    int d[] = {98,72,10,22,17,66};
    int n = 6;
    vector<pair<int,int>> *adj;
    adj = new vector<pair<int,int>>[n+1];
    // cout << "hello" << endl;
    for(int i = 1;i<=n;i++){
        cout << "hello" << a[i-1] << endl;
        int x = a[i-1];
        adj[x].push_back({b[i-1],d[i-1]});
    }
     for(int i = 1;i<n+1;i++){
        cout << i ;
        for(auto j:adj[i]){
            cout << "-->" << j.first << " (" << j.second << ") " ;
        }
        cout << endl;
    }
}