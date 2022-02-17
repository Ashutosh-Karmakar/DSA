#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    list<int> *adj;
    bool *visited;
    int *color;
    int V;
    public:
    Graph(int V);
    void addEdge(int from,int to);
    void printEdge();
    bool bipartitePartition();
    bool isBipartite(int s);
};

Graph::Graph(int V){
    this->V = V;
    visited = new bool[V];
    color = new int[V];
    adj = new list<int>[V];
    for(int i= 0;i<V;i++){
        color[i] = -1;
        visited[i] = false;
    }
}
void Graph::addEdge(int from,int to){
    adj[from].push_back(to);
}

void Graph::printEdge(){
    for(int i=1;i<V;i++){
        cout << "\n" << i ;
        for(auto j:adj[i]){
            cout << "-->" << j;
        }
    }
}
bool Graph::bipartitePartition(){
    for(int i=1;i<V;i++){
        if(color[i] == -1){
            if(!isBipartite(i)){
                return false;
            }
        }
    }
    return true;
}
bool Graph::isBipartite(int s){
    queue<int> q;
    q.push(s);
    color[s] = 0;
    int cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i:adj[cur]){
            if(color[i] == color[cur]){
                return false;
            }
            if(color[i] == -1){
                color[i] = 1 - color[cur];
                q.push(i);
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

    cout << "The Graph Traversal is:" << endl;
    g.printEdge();

    cout << "\nThe graph is bipartite:" << endl;
    cout << g.bipartitePartition();
}