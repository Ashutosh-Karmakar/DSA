#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    int V;
    vector<int> *adj;
    bool *vis;
    int *color;
    public:
    Graph(int v);
    void addEdge(int from,int to);
    void bfs(int s);
    void dfs(int s);
    void print();
    bool bipartite();
    bool isBipartite(int s);

};
Graph::Graph(int v){
    V = v;
    adj = new vector<int>[V];
    vis = new bool(V);
    color = new int(V);
    for(int i=0;i<V;i++){
        vis[i] = false;
        color[i] = -1;
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
bool Graph::bipartite(){
    for(int i=0;i<V;i++){
        if(color[i] == -1){
        return isBipartite(i);
        }
    }
}
bool Graph::isBipartite(int s){
    queue<int> que;
    que.push(s);
    int cur;
    color[s] = 0;
    while(!que.empty()){
        cur = que.front();
        que.pop();
        for(int i:adj[cur]){
            if(color[i] == color[cur]){
                return false;
            }
            else if(color[i] == -1){
                color[i] = 1-color[i];
            }
        }
    }
    return true;
}

int main(){

    int V =6;
    Graph g(V);
    cout << "hellp";
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,2);
    g.addEdge(3,5);
    g.addEdge(4,2);
    g.addEdge(4,5);
    g.addEdge(5,3);
    g.addEdge(5,4);


    
    g.print();
    cout << endl;
    cout << g.bipartite() << endl;
}