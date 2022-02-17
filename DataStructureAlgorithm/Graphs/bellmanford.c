#include<stdio.h>
#define max 6//no of vertices
#define INFINITY 99999
int adj[max][max];
void addEdges(int from , int to,int w){
    adj[from][to] = w;
}
void printMatrix(){
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            printf("%d\t",adj[i][j]);
        }
        printf("\n\n");
    }
}
void bellmanFord(int s){//s is the vertex to start
    int distance[max];
    int previous[max];
    for(int i=0;i<max;i++){
        distance[i] = INFINITY;//seting it to max value like infinity
        previous[i] = -1;//setting it to null
    }
    distance[s] = 0;
    // printf("\n%d\n",adj[0][5]);
    for(int k =0;k<max;k++){
   
        for(int i=0;i<max;i++){
            for(int j=0;j<max;j++){
                if(adj[i][j]!=0 && distance[j] > distance[i] + adj[i][j]){
                    distance[j] = distance[i] + adj[i][j];
                    previous[j] = i;
                }
            }
        }

                         printf("\nThe distance array if %d:\n",k);
                    for(int l=0;l<max;l++){
                        printf("%d\t",distance[l]);
                    }
    }
    printf("\n\nThe final distance array:\n");
    for(int i=0;i<max;i++){
        printf("%d\t",distance[i]);
    }
    printf("\nThe final path array:\n");
    for(int i=0;i<max;i++){
        printf("%d\t",previous[i]);
    }


}
int main(){
    addEdges(0,1,8);
    addEdges(0,5,10);
    addEdges(1,2,1);
    addEdges(2,3,-1);
    addEdges(2,5,-4);
    addEdges(3,4,-2);
    addEdges(4,5,1);
    addEdges(5,3,2);

    printMatrix();
    bellmanFord(0);

}