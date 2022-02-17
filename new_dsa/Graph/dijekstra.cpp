#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void addEdge(vector<pair<int,int>> *adj,int from,int to,int wt){
    adj[from].push_back({to,wt});
}
void printEdges(vector<pair<int,int>> *adj,int V){
    for(int i=1;i<=V;i++){
        for(auto it:adj[i]){
            cout << i << "->" << it.first << "  (" << it.second << ") ";
        }
        cout << endl;
    }
}

void dijekstra(vector<pair<int,int>> *adj,int src,int V){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({src,0});
    
    vector<int> dist(V+1,INT_MAX);
    dist[src] = 0;
    while(!pq.empty()){
        int curNode =  pq.top().first;
        int dist_trav = pq.top().second;
        // cout << curNode << " " << dist_trav << endl;
        pq.pop();
        for(auto it:adj[curNode]){
            // cout << "             "<< it.first << dist[it.first] << endl;
            if(dist[it.first] > dist_trav + it.second){
                dist[it.first] = dist_trav + it.second;
                pq.push({it.first,dist[it.first]});
            }
        }
    }
    cout << "\nThe Distance of Each Node From " << src << " are:" << endl;
    int j =0;
    for(int i:dist){
        cout << j << " - " << i << endl;
        j++;
    }

}

int main(){
    int V = 6;

    vector<pair<int,int>> adj[V+1];

    addEdge(adj,1,4,10);
    addEdge(adj,1,3,100);
    addEdge(adj,3,2,6);
    addEdge(adj,4,2,150);
    addEdge(adj,2,5,2);
    addEdge(adj,2,6,200);
    addEdge(adj,5,6,36);
    printEdges(adj,V);
    dijekstra(adj,1,V);


}