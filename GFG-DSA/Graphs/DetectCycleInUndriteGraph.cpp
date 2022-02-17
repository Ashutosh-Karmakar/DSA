#include<iostream>
#include<list>
#include<stack>
#include<vector>
using namespace std;

class Disjoint{
    int *parent;
    int V;

    public:
    Disjoint(int V);
    void union_op(int from ,int to);
    int find(int v);
};
Disjoint::Disjoint(int V){
    this->V = V;
    parent = new int(V);
    for(int i=0;i<V;i++){
        parent[i] = -1;
    }
}


class Graph{
    int V;
    list<int> *adj;
    
    vector<bool> visited;
    public:
    Graph(int V);
    void DFS(int v);
    void addEdge(int from , int to);
    void printEdges();
    void createEdgeList(vector<pair<int,int>> *edge);
    bool isCyclic(vector<pair<int,int>> edge,Disjoint d);

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
    // adj[to].push_back(from);
    
}

void Graph::printEdges(){
    for(int i=0;i<V;i++){
        
        cout << "\n" << i ;
        for(auto a:adj[i]){
            cout << "-->" << a;
        }
    }
}
int Disjoint::find(int v){
    if(parent[v] == -1){
        return v;
    }
    return find(parent[v]);

}
void Disjoint::union_op(int from,int to){
    from = find(from);
    to = find(to);
    parent[from] = to;
}
bool Graph::isCyclic(vector<pair<int,int>> edge,Disjoint d){
    int from,to;
    for(auto i = edge.begin();i!=edge.end();i++){
        from = d.find(i->first);
        to = d.find(i->second);
        if(from == to){
            return true;    
        }
        d.union_op(from,to);
    }
    return false;
}
void Graph::createEdgeList(vector<pair<int,int>> *edge){
    for(int i=0;i<V;i++){
        for(auto j:adj[i]){
            (*edge).push_back({i,j});
        }
    }
}



int main(){
    int n = 4;
    Graph g(n);
    g.addEdge( 0, 1);
    g.addEdge( 0, 2);
    g.addEdge( 1, 2);
    g.addEdge( 2, 3);
    g.printEdges();
    cout << "\nBFS of the tree is : " << endl;
    

    vector<pair<int,int>> edgeList;
    g.createEdgeList(&edgeList);
    for(pair<int,int> i:edgeList){
        cout << i.first << " : " << i.second << endl;
    }
    cout << "\nThe Cycle :" << endl;
    Disjoint d(n);
    cout << g.isCyclic(edgeList,d);


}