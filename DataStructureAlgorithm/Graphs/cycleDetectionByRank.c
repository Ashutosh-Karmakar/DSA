#include<stdio.h>
#define N 5
int findRoot(int par[],int v){
    if(par[v] == -1){
        return v;
    }
    return par[v] = findRoot(par,par[v]);
}
void unionOp(int par[],int ran[],int f,int t){
    if(ran[f] > ran[t]){
        par[t] = f;
    }
    else if(ran[f] < ran[t]){
        par[f] = t;
    }
    else{
        par[f] = t;
        ran[t]+=1;
        
    }

}
int isCycle(int graph[][2],int par[],int ran[]){
    int f,t;
    for(int i=0;i<N;i++){
        f = graph[i][0];
        t = graph[i][1];
        printf("\n%d %d\n",f,t);
        printf("\npar[4-5] : %d - %d\n",par[3],par[4]);
        f = findRoot(par,f);
        t = findRoot(par,t);
        
        if(f==t){
            return 1;
        }
        printf("\npar[4-5] : %d - %d\n",par[3],par[4]);
        
        printf("\n%d %d\n",f,t);
        unionOp(par,ran,f,t);
        
    }
    return 0;
}


int main(){
    int graph[N][2]= {{0,1},{2,3},{1,2},{0,4},{4,3}};
    int parent[N];
    int rank[N];
    for(int i=0;i<N;i++){
        parent[i] = -1;
        rank[i] = 0;
    }
    
    printf("\nThe graph is:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++){
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
printf("\ncycle : %d\n",isCycle(graph,parent,rank));
    printf("\nThe parent is:\n");
    for(int i=0;i<N;i++){
        // for(int j=0;j<2;j++){
            printf("%d\t",parent[i]);
        // }
        printf("\n");
    }

    

    //TC : O(E*V)
    
}