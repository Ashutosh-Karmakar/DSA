#include<iostream>
#include<vector>
using namespace std;

int find(vector<int> &parent,int v){
    if(parent[v] == -1){
        return v;
    }
    return parent[v] = find(parent,parent[v]);
}

void union_op(vector<int> &rank,vector<int> &parent,int from ,int to){
    from = find(parent,from);
    to = find(parent,to);
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
bool isCycle(int N,vector<pair<int,int>> edges){
    vector<int> parent(N,-1);
    vector<int> rank(N,0);
    for(auto it=edges.begin();it!=edges.end();it++){
        int from = it->first;
        int to = it->second;
        from = find(parent,from);
        to = find(parent, to);
        if(from == to){
            return true;
        }
        union_op(rank,parent,from,to);
    }
    return false;
}

int main(){
    int N ;
    cin >> N;
    vector<pair<int,int>> edges;
    for(int i=0;i<N;i++){
        int i1;
        cin >> i1;
        int i2;
        cin >> i2;
        edges.push_back({i1,i2});
    } 
    cout << isCycle(N,edges) << endl;
}