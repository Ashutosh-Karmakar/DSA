#include<iostream>
#include<vector>
using namespace std;

int find(int x,vector<int> &parent){
        if(parent[x] == -1){
            return x;
        }
        return find(parent[x],parent);
    }
void union_op(int from,int to,vector<int> &parent){
    from = find(from,parent);
    to = find(to,parent);
    parent[from] = to;
}
bool isCycle(int V, vector<pair<int,int>> edges) {
    
    vector<int> parent(V,-1);
    
    int from,to;
    for(auto it=edges.begin();it!=edges.end();it++){
        from = find(it->first,parent);
        to = find(it->second,parent);
        if(from == to){
            return true;
        }
        union_op(from,to,parent);
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