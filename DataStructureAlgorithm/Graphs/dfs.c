#include<stdio.h>
#include<stdlib.h>
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
    // printf("1st : %d : %d\n",from,graph->adjList[from]->data);
    

    temp = createNode(from);
    // printf("2nd : %d\n",temp->data);
    temp->next = graph->adjList[to];
    graph->adjList[to] = temp;

}
void printGraph(Graph *graph,int v){
    
    for(int i = 0;i<v;i++){
        node *temp = graph->adjList[i];
        // printf("\n");

        printf("\n%d -> ",i);
        while(temp != NULL){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
    }
}

void DFS(Graph *graph,int v,int vis[]){
    vis[v] = 1;
    printf("%d\t",v);
    
    node *temp = graph->adjList[v];
    while(temp != NULL){
        if(vis[temp->data] != 1){
            DFS(graph,temp->data,vis);
        }
        temp = temp->next;
    }
    
}

int main(){
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 4);

    int visited[5];
    for(int i=0;i<5;i++){
        visited[i] = -1;
    }
    // printGraph(graph,5);

    printf("\nDFS CALLING:\n");
    node *temp =graph->adjList[0];
    while(temp!=NULL){
        if(visited[temp->data] != 1)
            DFS(graph,1,visited);
        temp = temp->next;

    }
    

}