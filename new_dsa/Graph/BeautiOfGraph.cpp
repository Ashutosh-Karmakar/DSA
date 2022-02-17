#include<iostream>
#include<vector>
using namespace std;

void addEdges(vector<int> *adj,int from,int to){
    adj[from].push_back(to);
}

void printEdge(vector<int> *adj,string names,int V){
    for(int i=1;i<=V;i++){
        cout << names[i-1] ;
        for(auto it:adj[i]){
            cout << "->" << names[it-1];
        }
        cout << endl;
    }
}




int main(){
    int V;
    int E;
    cin >> V;
    cin >> E;
    string names;
    cin >> names;
    vector<int> *adj = new vector<int>[V];
    int from,to;
    for(int i=1;i<=E;i++){
        cin >> from;
        cin >> to;
        addEdges(adj,from,to);
    }
    printEdge(adj,names,V);

    
}