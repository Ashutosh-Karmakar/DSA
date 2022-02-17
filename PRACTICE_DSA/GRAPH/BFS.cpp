#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    vector<int> *adj;
    bool *vis;
    int V;
    public:
    Graph(int V);
    void addEdge(int from,int to);
    void printEdge();
    void BFS(int s);
};
Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V+1];
    vis = new bool[V+1];
    for(int i=0;i<=V;i++){
        vis[i] = false;
    }
}

void Graph::addEdge(int from,int to){
    adj[from].push_back(to);
    // adj[to].push_back(from);
}
void Graph::printEdge(){
    for(int i=1;i<=V;i++){
        cout << i;
        for(int j:adj[i]){
            cout <<"-->" << j ;
        }
        cout << endl;
    }
}
void Graph::BFS(int s){
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int cur = q.front();
            q.pop();
            cout << cur << " ";
            for(int i:adj[cur]){
                if(vis[i] == false){
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }    
}

int main(){
    int N = 4;
    Graph g(N);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 4);

    cout << "The Graph is:" << endl;
    g.printEdge();
    cout << endl;
    g.BFS(1);
    cout << endl;

}