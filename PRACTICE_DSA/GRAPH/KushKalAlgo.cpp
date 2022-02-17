#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(vector<int> a,vector<int> b){
    return a[2] < b[2];
}
vector<int> par;
vector<int> rankOP;
class Graph{
    vector<vector<int>> adj;
    int V,E;
    public:
    Graph(int V,int W);
    void addEdge(int from,int to,int w);
    void kushkal();
};
Graph::Graph(int V,int W){
    this->V = V;
    E = W;
    for(int i=0;i<V;i++){
        par.push_back(-1);
        rankOP.push_back(0);
    }
}
void Graph::addEdge(int from,int to,int w){
    vector<int> temp;
    temp.push_back(from);
    temp.push_back(to);
    temp.push_back(w);
    adj.push_back(temp);
}
int find(int x){
    if(par[x] == -1){
        return x;
    }
    return par[x] = find(par[x]);
}
void unionOp(int from,int to){
    // from = find(from);
    // to = find(to);
    if(rankOP[from] == rankOP[to]){
        par[from] = to;
        rankOP[to]++;
    }
    else{
        if(rankOP[from] > rankOP[to]){
            par[to] = from;
            // rankOP[from]++;
        }
        else if(rankOP[to] > rankOP[from]){
            par[from] = to;
            // rankOP[to]++;
        }
    }
}
bool isCyclic(int from,int to){
    from = find(from);
    to   = find(to);
    if(from == to){
        return true;
    }
    unionOp(from,to);
    return false;
}

void Graph::kushkal(){
    sort(adj.begin(),adj.end(),comp);
    int i = 0;
    int k = 0;
    while(k<V-1 && i<E){
        // cout <<i << endl;
        int from = adj[i][0];
        int to = adj[i][1];
        int w = adj[i][2];
        if(isCyclic(from,to) == false){
            cout << from << " ";
            cout << to << " ";
            cout << w << " ";
            cout << endl;
            k++;
        }
        i++;
    }
}

int main(){
    int N = 4;
    int E = 6;
    Graph g(N,E);
    g.addEdge(0,1,10);
    g.addEdge(0,2,6);
    g.addEdge(0,3,5);
    g.addEdge(1,3,15);
    g.addEdge(2,3,4);
    g.kushkal();
}
