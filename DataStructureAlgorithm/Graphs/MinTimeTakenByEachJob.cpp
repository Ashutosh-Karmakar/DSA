#include<iostream>
#include<queue>
#include<stack>
#include<vector>


using namespace std;
vector<int> *adj;
vector<int> indegre;
queue<int> q;
vector<int> job(50);
void addEdge(int from,int to){
    adj[from].push_back(to);
    indegre[to]++;
}
void minTimeJob(){
    int t = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i:adj[cur]){
            indegre[i]--;
            if(indegre[i] == 0){
                job[i] = job[cur] + 1;
                q.push(i);
            }
        }
    }
    for(int i:job){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    
    int N=10;
    adj = new vector<int>[N+2]; 
    for(int i=1;i<N+1;i++){
        indegre.push_back(0);
    }
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);
    for(int i=1;i<N+1;i++){
        if(indegre[i] == 0){
            q.push(i);
            job[i] = 1;
        }
    }
    minTimeJob();
    
}