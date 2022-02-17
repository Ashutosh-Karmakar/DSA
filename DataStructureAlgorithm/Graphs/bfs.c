#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct Node{
    int data;
    struct Node *next;
}node;
typedef struct Graph{
    int *visited;
    int vertex;
    node **adjList;
}Graph;

int que[max];
int front = -1;
int rear = -1;

void Enque(int x){
    if(rear == max){
        printf("The que is full");
        return;
    }
    if(front == -1)front++;
    que[++rear] = x;
}
int Deque(){
    if(front == -1){
        printf("The que is empty");
        return -1;
    }
    return que[front++];
}

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
void printQue(){
    if(front==-1){printf("\nQue is empty\n");return;}
    for(int i = front;i<rear+1;i++){
        printf("%d\t",que[i]);
    }
}

void BFS(Graph *graph,int v,int vis[]){
    vis[v] = 1;
    
    Enque(v);
    
    while(front<=rear){
        printf("\nQue:");
        printQue();
        printf("\n\n");
        int curVertex = Deque();
        printf("curvertex: %d\n",curVertex);

        node *temp = graph->adjList[curVertex];

        while(temp != NULL){

            if(vis[temp->data] != 1){
                vis[temp->data] = 1;
                Enque(temp->data);
            }
            temp = temp->next;
        }
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

    printf("\nBFS CALLING:\n");
    // node *temp =graph->adjList[0];
    // while(temp!=NULL){
        // if(visited[temp->data] != 1)
            BFS(graph,0,visited);
        // temp = temp->next;

    // }
    

}