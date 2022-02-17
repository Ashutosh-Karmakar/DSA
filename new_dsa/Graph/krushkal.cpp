#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct Node{
    int from;
    int to;
    int wt;
    Node(int fr,int t,int w){
        from = fr;
        to = t;
        wt = w;
    }
};
void addEdges(vector<Node *> &edges,int from,int to,int wt){
    Node *n = new Node(from,to,wt);
    edges.push_back(n);
}
void printEdges(vector<Node *> edges){
    for(auto it:edges){
        cout << it->from << "-" << it->to << "  " << it->wt << endl;
    }
}
bool comparator(Node *n1,Node *n2){
    return n1->wt < n2->wt;
}
int find(int v,vector<int> &parent){
    if(parent[v] == -1){
        return v;
    }
    return parent[v] = find(parent[v],parent);
}

void union_op(vector<int> &parent,vector<int> &rank,int from,int to){
    if(rank[from] == rank[to]){
        parent[from] = to;
        rank[to]++;
    }
    else if(rank[from] < rank[to]){
        parent[from] = to;
    }
    else{
        parent[to] = from;
    }
}
bool isCyclic(int from,int to,int V,vector<int> &parent,vector<int> &rank){
    
    from = find(from,parent);
    to = find(to,parent);
    if(from == to){
        return true;
    }
    union_op(parent,rank,from,to);
    return false;

}
void krushkalAlgo(vector<Node *> &edges,int V,int E){
    vector<Node *> result;
    vector<int> parent(V,-1);
    vector<int> rank(V,0);
    sort(edges.begin(),edges.end(),comparator);
    int e = 0;
    int i = 0;
    while(e < V-1 && i < E){
        if(isCyclic(edges[i]->from,edges[i]->to,V,parent,rank) == false){
            e++;
            result.push_back(edges[i]);
        }
        i++;
    }
    printEdges(result);


}
int main(){
    int E,from,to,wt ;
    vector<Node *> edges;
    int V = 4;
    E = 5;
    addEdges(edges,0,1,10);
    addEdges(edges,0,2,6);
    addEdges(edges,0,3,5);
    addEdges(edges,1,3,15);
    addEdges(edges,2,3,4);

    printEdges(edges);
    cout << endl;
    krushkalAlgo(edges,V,E);
    cout << endl;
    printEdges(edges);
    cout << endl;

}