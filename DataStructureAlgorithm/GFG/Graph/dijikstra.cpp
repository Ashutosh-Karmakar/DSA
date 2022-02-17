#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N = 6;
vector<pair<int,int>> adj[N+1];// = new vector<pair<int,int>>(N+1);
void addEdge(int from,int to,int w){
    adj[from].push_back({to,w});

}

int main(){
    addEdge(1,4,10);
    addEdge(1,3,100);
    addEdge(3,2,6);
    addEdge(4,2,150);
    addEdge(2,5,2);
    addEdge(2,6,200);
    addEdge(5,6,36);
    cout << "The Graph is" << endl;
    for(int i =1;i<N+1;i++){
        cout <<"\n" << i ;
        for(pair<int,int> p:adj[i]){
            cout << "-->" << p.first << "( " << p.second<< " )";
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    int src = 1;
    vector<int> dist(N+1,9999);
    q.push({src,0});
    dist[1] = 0;
    while(!q.empty()){
        int curPos = q.top().first;
        int distanceTravelled = q.top().second;
        q.pop();
        for(auto it:adj[curPos]){
            if(dist[it.first] > distanceTravelled + it.second ){
                dist[it.first] = distanceTravelled + it.second;
                q.push({it.first,dist[it.first]});
            }
        }
    }

    cout << "\nDistance from src 1: " << endl;
    for(int i:dist){
        cout << i << " ";
    }
    cout << endl;
}

//O( (V + E ) log V)
