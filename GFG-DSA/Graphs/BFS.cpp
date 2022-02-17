#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addEdge(vector<int> v[],int from,int to){
    v[from].push_back(to);
    // v[to].push_back(from);
}

void printEdges(vector<int> v[],int n){
    for(int i=0;i<n;i++){
        //cout << "\nThe adjacency List fot vertex " << i << //" :\nhead" ;
        cout << "\n" << i ;
        for(auto a:v[i]){
            cout << "-->" << a;
        }
    }
}

void BFS(vector<int> v[] , int n,int start){
    queue<int> q;
    bool visited[6];
    for(int i = 0 ; i < n;i++){
        visited[i] = false;
    }
    q.push(start);
    visited[start] = true;
    int cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i:v[cur]){
            if(visited[i] == false){
                visited[i] = true;
                q.push(i);
            }
        }

    }
}

int main(){
    const int n = 4;
    vector<int> v[n];
    addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 1, 2);
    addEdge(v, 2, 0);
    addEdge(v, 2, 3);
    addEdge(v, 3, 3);
    printEdges(v,n);
    cout << "\nBFS of the tree is : " << endl;
    BFS(v,n,2);

}