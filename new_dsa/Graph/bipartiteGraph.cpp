#include<iostream>

#include<queue>

using namespace std;
void addEdge(vector<int> *adj,int from,int to){
        adj[from].push_back(to);
}
void printEdge(vector<int> *adj,int V){
    for(int i=0;i<V;i++){
        cout << i ;
        for(auto it:adj[i]){
            cout << "->" << it ;
        }
        cout << endl;
    }
}

bool isBipartite(vector<int> *adj,vector<int> &clr,int src){
    clr[src] = 0;
    queue<int> que;
    que.push(src);
    while(!que.empty()){
        int node = que.front();
        que.pop();
        for(auto it:adj[node]){
            if(clr[it] == -1){
                clr[it] = 1-clr[node];
                que.push(it);
            }
            else if(clr[it] == clr[node]){
                return false;
            }
        }
    }
    return true;

}

int main(){
    int V = 4;
    vector<int> *adj = new vector<int>[V];
    vector<int> clr(V,-1);

    addEdge(adj,0,1);
    addEdge(adj,0,3);
    addEdge(adj,1,0);
    addEdge(adj,1,2);
    addEdge(adj,2,1);
    addEdge(adj,2,3);
    addEdge(adj,3,0);
    addEdge(adj,3,2);

    printEdge(adj,V);
    cout << isBipartite(adj,clr,0) << endl;

}
