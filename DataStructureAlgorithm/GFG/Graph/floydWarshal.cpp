#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void addEdge(vector<vector<int>> &adj,int u,int v,int w){
    adj[u][v] = w;
    adj[v][u] = w;
}
int main(){
    int N = 5;
    vector<vector<int>> adj(N+1,vector<int>(N+1,99999999));
    addEdge(adj,1,2,15);
    addEdge(adj,1,3,20);
    addEdge(adj,2,3,40);
    addEdge(adj,2,4,50);
    addEdge(adj,3,4,22);
    addEdge(adj,3,5,10);
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= N ;j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    for(int k=1;k<=N;k++){
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<N;j++){
                if(adj[i][k] != 99999999 && adj[k][j] != 99999999){
                    adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
                }
            }
        }
    }
    cout << "after algo" << endl;
     for(int i = 1;i <= N;i++){
        for(int j = 1;j <= N ;j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }


}