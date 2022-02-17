#include<iostream>
#include<list>
#include<stack>
#include<vector>
using namespace std;
class Graph{
    int V;
    list<int> *adj;
    
    vector<bool> visited;
    public:
    Graph(int V);
    void DFS(int v);
    void addEdge(int from , int to);
    void printEdges();

};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
    // visited = new int[V];
    for(int i = 0 ; i < V;i++){
        visited.push_back(false);
    }
}

void Graph::addEdge(int from,int to){
    adj[from].push_back(to);
}

void Graph::printEdges(){
    for(int i=0;i<V;i++){     
        cout << "\n" << i ;
        for(auto a:adj[i]){
            cout << "-->" << a;
        }
    }
}

void Graph::DFS(int v){
    visited[v] = true;
    cout << v << " ";
    for(int i:adj[v]){
        if(visited[i] == false){
            DFS(i);
        }
    }
}

int main(){
    int n = 4;
    Graph g(n);
    g.addEdge( 0, 1);
    g.addEdge( 0, 2);
    g.addEdge( 1, 2);
    g.addEdge( 2, 0);
    g.addEdge( 2, 3);
    g.addEdge( 3, 3);
    g.printEdges();
    cout << "\nBFS of the tree is : " << endl;
    g.DFS(2);

}