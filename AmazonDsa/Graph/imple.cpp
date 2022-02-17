#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    int V;
    vector<int> *adj;
    bool *vis;
    public:
    Graph(int v);
    void addEdge(int from,int to);
    void bfs(int s);
    void dfs(int s);
    void print();

};
Graph::Graph(int v){
    V = v;
    adj = new vector<int>[V];
    vis = new bool(V);
    for(int i=0;i<V;i++){
        vis[i] = false;
    }
}
void Graph::addEdge(int from,int to){
    adj[from].push_back(to);
    adj[to].push_back(from);
}
void Graph::print(){
    for(int i=0;i<V;i++){
        cout << "\n" << i;
        for(int j:adj[i]){
            cout << "-->" << j ;
        }
    }
}
void Graph::bfs(int s){
    queue<int> que;
    que.push(s);
    vis[s] = true;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        cout << cur << " ";
        for(int i:adj[cur]){
            if(vis[i] == false){
                que.push(i);
                vis[i] = true;           
            }
        }
    }
}
void Graph::dfs(int s){
    vis[s] = true;
    cout << s << " ";
    for(int i:adj[s]){
        if(vis[i] == false){
            dfs(i);
        }
    }
}

int main(){

    const int n = 4;
    Graph g(n);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    g.print();
    cout << endl;
    g.d`fs(0);
}