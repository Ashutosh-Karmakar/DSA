#include<stdio.h>
#define V 6
int isAdj(int g[][V],int i,int j){
    return g[i][j];
}
int Minimum(int ver[V],int mst[V]){
    int min=99999;
    int vertex;
    for(int i=0;i<V;i++){
        if(mst[i]==0 && min > ver[i]){
            vertex = i;
            min = ver[i];
        }
    }
    return vertex;
}
void primeAlgo(int graph[][V]){
    int mst[V];
    int parent[V];
    int ver[V];
    ver[0]=0;
    mst[0] = 0;
    parent[0] = -1;
    for(int i=1;i<V;i++){
        ver[i] = 99999;
        mst[i] = 0;
    }
    int cur = -1;
    for(int i=0;i<V;i++){
        cur = Minimum(ver,mst);//returns the vertes with min weight
        mst[cur] = 1;
        for(int j=0;j<V;j++){
            if(graph[cur][j]!=0){
                if(ver[j] > graph[cur][j] && mst[j] == 0){
                    ver[j] = graph[cur][j];
                    parent[j] = cur;
                }
            }
        }
    }
    printf("\nThe parent array:\n");
    for(int i=0;i<V;i++){
        printf("%d\t",parent[i]);
    }
    printf("\n");
}
int main(){
    int graph[V][V] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };
    primeAlgo(graph);
    
}