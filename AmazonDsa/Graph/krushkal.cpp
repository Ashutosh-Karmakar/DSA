#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    int from;
    int to;
    int wt;
    Node(int f,int t,int w){
        from = f;
        to = t;
        wt = w;
    }
};

bool comp(Node *a,Node *b){
    return a->wt < b->wt;
}
int find(int x,vector<int> &parent){
    if(parent[x] == -1){
        return x;
    }
    return parent[x] = find(parent[x],parent);
}
void unionOp(int from,int to,vector<int> &parent,vector<int> &rank){
    if(rank[from] == rank[to]){
        parent[from] = to;
        rank[to]++;
    }
    else if(rank[from] > rank[to]){
        parent[to] = from;
    }
    else{
        parent[from] = to;
    }
}
bool isCyclic(int from,int to,vector<int> &parent,vector<int> &rank){
    from = find(from,parent);
    to = find(to,parent);
    if(from == to){
        return true;
    }
    unionOp(from,to,parent,rank);
    return false;
}
void printedges(vector<Node *> edges){
    for(int i=0;i<edges.size();i++){
        cout << edges[i]->from<< "-->" << edges[i]->to << " ( " << edges[i]->wt << " ) "<< endl;
    }
}

void krushkal(vector<Node *> edges,int v){
    vector<Node *> result;
    int e = 0;
    vector<int> parent(v,-1);
    vector<int> rank(v,0);
    sort(edges.begin(),edges.end(),comp);
    int i=0;
    while(e < v-1 && i < v){
        if(!isCyclic(edges[i]->from,edges[i]->to,parent,rank)){
            result.push_back(edges[i]);
            cout << "\n\n" << find(edges[i]->from,parent) << " " << find(edges[i]->to,parent) << endl;
            e++;
        }
        i++;
    }
    printedges(edges);
    cout << "\n\n results it is:" << endl;
    printedges(result);
    
}


int main(){
    int v=4;
    int e=5;
    vector<Node *> edges;
    edges.push_back(new Node(0,1,10));
    edges.push_back(new Node(0,2,6));
    edges.push_back(new Node(0,3,5));
    edges.push_back(new Node(1,3,15));
    edges.push_back(new Node(2,3,4));
    
    cout << "bye" << endl;
    printedges(edges);
    cout << "\n\nEdges it is:" << endl;
    krushkal(edges,v);
}