#include<stdio.h>
#define N 10
#define V 6
typedef struct Edge{
    int f;
    int t;
    int w;
}edge;
int find(int par[],int v){
    if(par[v] == -1){
        return v;
    }
    return par[v] = find(par,par[v]);
}
void UnionOp(int par[],int rank[],int f,int t){
    if(rank[f] > rank[t]){
        par[t] = f;
    }
    else if(rank[t] > rank[f]){
        par[f] = t;
    }
    else{
        par[f] = t;
        rank[t]++;
    }

}
int isCycle(edge E[],int par[],int rank[],int i){
    int f = E[i].f;
    int t = E[i].t;
    f = find(par,f);
    t = find(par,t);
 
    if(f==t){
        return 1;
    }
    UnionOp(par,rank,f,t);
    return 0;
   
}
void MST(edge E[],int par[],int rank[]){
    int i=0;
    int k=0;
    while(k<V-1 && i<N){
        printf("%d",i);
        if(isCycle(E,par,rank,i) == 0){
            printf("\n%d - %d : %d :: %d\n",E[i].f,E[i].t,E[i].w,k);
            k++;
        }
        i++;
        
    }

}
void main(){
    int par[V];
    int ran[V];
   
    


    edge E[N];
    E[0].f = 0;
    E[0].t = 1;
    E[0].w = 1;

    E[1].f = 1;
    E[1].t = 3;
    E[1].w = 1;
    
    E[2].f = 2;
    E[2].t = 4;
    E[2].w = 1;
    
    E[3].f = 0;
    E[3].t = 2;
    E[3].w = 2;
    
    E[4].f = 2;
    E[4].t = 3;
    E[4].w = 2;
    
    E[5].f = 3;
    E[5].t = 4;
    E[5].w = 2;
    
    E[6].f = 1;
    E[6].t = 2;
    E[6].w = 3;
    
    E[7].f = 1;
    E[7].t = 4;
    E[7].w = 3;
    
    E[8].f = 4;
    E[8].t = 5;
    E[8].w = 3;
    
    E[9].f = 3;
    E[9].t = 5;
    E[9].w = 4;

    printf("F - T : W\n---------\n");
    for(int i=0;i<N;i++){
        printf("%d - %d : %d\n",E[i].f,E[i].t,E[i].w);
    }
    for(int i=0;i<V;i++){
        par[i] = -1;
        ran[i] = 0;
    }

    MST(E,par,ran);
    
    printf("\n\npar:\n");
    for(int i=0;i<V;i++){
        printf("%d\t",par[i]);
    }

}