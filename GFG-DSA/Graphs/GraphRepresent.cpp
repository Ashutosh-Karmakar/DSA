#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<int> v[],int from,int to){
    v[from].push_back(to);
    v[to].push_back(from);
}

void printEdges(vector<int> v[],int n){
    for(int i=0;i<n;i++){
        cout << "\nThe adjacency List fot vertex " << i << " :\nhead" ;
        for(auto a:v[i]){
            cout << "-->" << a;
        }
    }
}

int main(){
    const int n = 5;
    vector<int> v[n];
    addEdge(v, 0, 1);
    addEdge(v, 0, 4);
    addEdge(v, 1, 2);
    addEdge(v, 1, 3);
    addEdge(v, 1, 4);
    addEdge(v, 2, 3);
    addEdge(v, 3, 4);
    printEdges(v,n);

}