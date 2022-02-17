#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    vector<int> *adj;
    int V;
    bool *vis;
    public:
    Graph(int v);
    void printEdges();
    void addEdge(int from,int to);
    void BFS(int i,int target);
    void DFS(int i);
};
Graph::Graph(int v){
    V = v;
    adj = new vector<int>[V];
    vis = new bool[V];
    for(int i=0;i<V;i++){
        vis[i] = false;
    }
}
void Graph::addEdge(int from,int to){
    adj[from].push_back(to);
    adj[to].push_back(from);
}
void Graph::printEdges(){
    for(int i=0;i<V;i++){
        cout << i ;
        for(auto it:adj[i]){
            cout << " -> " << it ;
        }
        cout << endl;
    }
}
void Graph::DFS(int i){
    vis[i] = true;
    cout << i << " ";
    for(auto it:adj[i]){
        if(vis[it] == false){
            DFS(it);
        }
    }
}
void Graph::BFS(int i,int target){
    int level = 0;
    queue<int> que;
    que.push(i);
    vis[i] = true;
    while(!que.empty()){
        int size = que.size();
        while(size--){
            int cur = que.front();
            que.pop();
            if(cur == target){
                cout <<"Element is found in : " << level << endl;
                return;
            }
            // cout << cur << " ";
            for(auto it:adj[cur]){
                if(!vis[it]){   
                    que.push(it);
                    vis[it] = true;
                }
            }
        }
        level++;
        cout << endl;
    }
}
int main(){
    int V = 7;
    Graph g(V);
    g.addEdge(6,5);
    
    g.addEdge(1,2);
    g.addEdge(2,3);
    
    g.addEdge(3,5);
    
    g.addEdge(1,4);
    g.addEdge(1,6);
    
    g.printEdges();
    g.BFS(1,5);
}