#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int x;
    int w;
    Node(int x,int w){
        this->x = x;
        this->w = w;
    }
};

class Graph{
    int V;
    vector<bool> visited;
    list<Node> *adj;
    stack<int> st;
    int *distance;
    public:
    Graph(int V);
    void addEdge(int from,int to,int w);
    void printEdge();
    void topologicalSorting(int s);
    void start();
    void maxDistance(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<Node>[V];
    distance = new int(V);
    for(int i=0;i<V;i++){
        distance[i] = -999999;
        visited.push_back(false);
    }
}
void Graph::addEdge(int from,int to,int w){
    Node m(to,w);
    adj[from].push_back(m);
}
void Graph::printEdge(){
    for(int i=0;i<V;i++){
        cout << i ;
        for(auto a:adj[i]){
            cout << "-->" << a.x << " (" << a.w << ") " ; 
        }
        cout << endl;
    }
}
void Graph::topologicalSorting(int s){
    visited[s] = true;
    cout << s << " ";
    for(Node a:adj[s]){
        if(!visited[a.x]){
            topologicalSorting(a.x);
        }
    }
    st.push(s);
}
void Graph::maxDistance(int s){
    distance[s] = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(distance[u] != -999999){
            for(Node a:adj[u]){
                if(distance[a.x] < distance[u] + a.w){
                    distance[a.x] = distance[u] + a.w;
                }
            }
        }
    }
    cout << "\nThe distance is:" << endl;
    for(int i=0;i<V;i++){
        cout << distance[i] << " ";
    }
    cout << endl;
}

int main(){
Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printEdge();
    cout << " dfjdf " << endl;
    g.topologicalSorting(1);
    g.maxDistance(1);

    
    
}
