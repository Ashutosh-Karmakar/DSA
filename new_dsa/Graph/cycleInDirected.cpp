#include<iostream>
using namespace std;

#include<iostream>
#include<vector>
using namespace std;


bool isCycle(int N,vector<int> *adj,vector<bool> &vis,vector<bool> &restack,int v){
    vis[v] = true;
    restack[v] = true;

    for(auto it:adj[v]){
        if(!vis[it] && isCycle(N,adj,vis,restack,it)){
            return true;
        }
        if(restack[it]){
            return true;
        }
    }
    restack[v] = false;
    return false;
    
}
void addEdge(vector<int> *adj,int from,int to){
    adj[from].push_back(to);
}

int main(){
    int N ;
    N = 4;
    vector<int> adj[4];
    addEdge(adj,0, 1);
    addEdge(adj,0, 2);
    addEdge(adj,1, 2);
    // addEdge(adj,2, 0);
    addEdge(adj,2, 3);
    // addEdge(adj,3, 3);
    vector<bool> restack(N,false);
    vector<bool> vis(N,false);
    bool res = false;
    for(int i=0;i<N;i++){
        if(!vis[i] && isCycle(N,adj,vis,restack,0)==true){
            res = true;
        }
    }    
    cout << res;
}