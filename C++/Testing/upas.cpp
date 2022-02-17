#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}node;
typedef struct Graph{
    int *visited;
    int vertex;
    node **adjList;
}Graph;

node* createNode(int v){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = v;
    temp->next = NULL;
    return temp;
}

Graph* createGraph(int nV){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (node**)malloc(nV * sizeof(node*));
    for(int i=0;i<nV;i++){
        graph->adjList[i] = NULL;
    }
    return graph;
}


void addEdge(Graph *graph,int from ,int to){
    node* temp = createNode(to);
    temp->next = graph->adjList[from];
    graph->adjList[from] = temp;
    temp = createNode(from);
    temp->next = graph->adjList[to];
    graph->adjList[to] = temp;

}
void printGraph(Graph *graph,int v){
    
    for(int i = 1;i<v;i++){
        node *temp = graph->adjList[i];
        cout <<"\n" <<  i<<" -> ";
        while(temp != NULL){
            cout <<temp->data << "-> ";
            temp = temp->next;
        }
    }
}


void BFS(Graph *graph,int v,int vis[],int dis[] ,int T,int C,int N){
    vis[v] = 1;
    
    queue<int> q;
    q.push(v);
    dis[v] = 0;
    
    while(!q.empty()){
        int curVertex = q.front();
        q.pop();

        node *temp = graph->adjList[curVertex];

        while(temp != NULL){

            if(vis[temp->data] != 1){
                if((T-C) < 0){
                    dis[temp->data] = C + T-(C-T) + dis[curVertex];
                }
                else{
                    dis[temp->data] = C + dis[curVertex];
                }
                vis[temp->data] = 1;
                q.push(temp->data);
            }
            temp = temp->next;
        }
    }
    if(T-C < 0)
    dis[N] -= T - (C-T);
    for(int i = 1;i<=N;i++){
        cout << dis[i] << " ";
    }
    cout << endl;
    
}

int main(){
    int C = 5;
    int T = 3;
    int N = 5;


    Graph* graph = createGraph(N+1);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    int visited[N+1];
    for(int i=1;i<6;i++){
        visited[i] = -1;
    }
    int dis[N+1];
    for(int i=1;i<=N;i++){
        dis[i] = 0;
    }
    printGraph(graph,6);
    cout << "\nDistance: "<<endl;
    BFS(graph,1,visited,dis,T,C,N);
}