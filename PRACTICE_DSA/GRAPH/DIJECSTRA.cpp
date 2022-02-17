#include<iostream>
#include<vector>
#include<queue>
#define INF 999999
using namespace std;
class Graph{
    vector<pair<int,int>> *adj;
    bool *vis;
    int V;
    public:
    Graph(int V);
    void addEdge(int from,int to,int w);
    void printEdge();
    void dijkstra(pair<int,int> s,vector<int> &dist);
};
Graph::Graph(int V){
    this->V = V;
    adj = new vector<pair<int,int>>[V+1];
    vis = new bool[V+1];
    for(int i=0;i<=V;i++){
        vis[i] = false;
    }
}

void Graph::addEdge(int from,int to,int w){
    adj[from].push_back({w,to});
    adj[to].push_back({w,from});
}
void Graph::printEdge(){
    for(int i=1;i<=V;i++){
        cout << i;
        for(auto j:adj[i]){
            cout <<"-->" << j.second << " (" << j.first <<") " ;
        }
        cout << endl;
    }
}
void Graph::dijkstra(pair<int,int> s,vector<int> &dist){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push(s);
    dist[s.second] = 0;
    while(!pq.empty()){
        pair<int,int> cur = pq.top();
        pq.pop();
        for(pair<int,int> i:adj[cur.second]){
            if(dist[i.second] > (cur.first + i.first)){
                dist[i.second] = cur.first + i.first;
                pq.push({dist[i.second],i.second});
            }
        }
    }
}
int main(){
    int V = 4;
    Graph g(V);
    g.addEdge(1,2,24);
    g.addEdge(1,4,20);
    g.addEdge(3,1,3);
    g.addEdge(4,3,12);
    vector<int> dist(V+1,INF);
    g.dijkstra({0,1},dist);
    cout << "The Graph is :" << endl;
    g.printEdge();
    cout << "\nThe distance matrix :" << endl;
    for(int i:dist){
        cout << i << " ";
    }
    cout << endl;   
}