#include<iostream>
#include<list>
#include<queue>
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
    void sortestPath(int s);

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
    adj[to].push_back(from);
}

void Graph::printEdges(){
    for(int i=0;i<V;i++){
        
        cout << "\n" << i ;
        for(auto a:adj[i]){
            cout << "-->" << a;
        }
    }
}

// void Graph::DFS(int v){
//     visited[v] = true;
//     cout << v << " ";
//     for(int i:adj[v]){
//         if(visited[i] == false){
//             DFS(i);
//         }
//     }
// }

void Graph::sortestPath(int s){
    queue<int> q;
    q.push(0);
    int level = 0;
    visited[0] = true;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int cur = q.front();
            q.pop();
            // cout << cur << " ";
            if(cur == s){
                cout << level << endl;
                break;
            }
            for(auto i:adj[cur]){
                if(visited[i] == false){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        level++;
    }


}

int main(){
    int n = 7;
    Graph g(n);
    g.addEdge( 0, 5);
    g.addEdge( 0, 4);
    g.addEdge( 0, 1);
    g.addEdge( 1, 2);
    g.addEdge( 1, 3);
    g.addEdge( 5, 3);
    g.addEdge( 5, 6);
    g.printEdges();
    cout << "\nBFS of the tree is : " << endl;
    g.sortestPath(6);

}