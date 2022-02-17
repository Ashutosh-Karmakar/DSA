#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<int> *adj,int from,int to){
        adj[from].push_back(to);
}
void printEdge(vector<int> *adj,int V){
    for(int i=0;i<V;i++){
        cout << i ;
        for(auto it:adj[i]){
            cout << "->" << it ;
        }
        cout << endl;
    }
}
int main(){
    int V = 6;
    vector<int> *adj = new vector<int>[V];
    addEdge(adj,5, 2);
    addEdge(adj,5, 0);
    addEdge(adj,4, 0);
    addEdge(adj,4, 1);
    addEdge(adj,2, 3);
    addEdge(adj,3, 1);
    printEdge(adj,V);

}