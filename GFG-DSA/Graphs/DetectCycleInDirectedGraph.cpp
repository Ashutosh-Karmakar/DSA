#include<iostream>
#include<vector>
using namespace std;
class Graph{
    int V;
    vector<int> *adj;
    bool *visited;
    bool *recArray;
    public:
    Graph(int V);
    void addEdges(int from,int to);
    bool detectCycle(int s);
    bool init();
    void printEdge();
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
    visited = new bool[V];
    recArray = new bool[V];
}
void Graph::addEdges(int from,int to){
    adj[from].push_back(to);
}

void Graph::printEdge(){
    for(int i=0;i<V;i++){
        cout << "\n" << i ;
        for(int j:adj[i]){
            cout << "-->" << j ;
        }
    }
}
bool Graph::init(){
    for(int i=0;i<V;i++){
        visited[i] = false;
        recArray[i] = false;
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            return detectCycle(i);
        }
    }
    return false;
}



bool Graph::detectCycle(int s){
    visited[s] = true;
    recArray[s] = true;
    for(auto it=adj[s].begin();it!=adj[s].end();it++){
        if(!visited[*it] && detectCycle(*it)){
            return true;
        }
        if(recArray[*it] == true){
            return true;
        }
    }
    recArray[s] = false;
    return false;
}
int main(){
    Graph g(4);
    g.addEdges(0, 1);
    g.addEdges(0, 2);
    g.addEdges(1, 2);
    g.addEdges(2, 0);
    g.addEdges(2, 3);
    g.addEdges(3, 3);

    cout << "The adjacency list :" << endl;
    g.printEdge();
    cout << endl;

    cout << "The graph contains a cycle or not: " << endl;
    cout << g.init() << endl;

}