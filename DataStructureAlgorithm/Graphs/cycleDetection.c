#include<stdio.h>
int findRoot(int ver[],int v){
    if(ver[v] == -1){
        return v;
    }
    findRoot(ver,ver[v]);
}
int isCycle(int graph[][2]){
    int ver[4];
    for(int i=0;i<4;i++){
        ver[i] = -1;
    }
    int f,t;
    for(int i=0;i<4;i++){
        f = graph[i][0];
        t = graph[i][1];
        f = findRoot(ver,f);
        t = findRoot(ver,t);
        if(f==t){
            return 1;
        }
        ver[f] = t;
    }
    return 0;
}


int main(){
    int graph[4][2]= {{0,1},{0,3},{2,3},{1,2}};
    
    printf("\nThe graph is:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }

    printf("\ncycle : %d\n",isCycle(graph));

    //TC : O(E*V)
    
}