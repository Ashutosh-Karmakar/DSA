#include<stdio.h>
    int v;
    
    
    int front = -1;
    int rear = -1;
    int v;
   
    int arr[200];
    void insert(int k){
        if(front == -1){
            front++;
        }
        arr[++rear] = k;
    }

    int pop(){
        return arr[front++];
    }

    int isBipartile(int G[4][4],int x,int color[]){
        for(int i=0;i<v;i++){
            color[i] = -1;
        }
        insert(x);
        while(front!= rear +1){
            int u = pop();
            
            if(G[u][u] == 1){
                return 0;
            }
            
            for(int i=0;i<v;++i){
                if(G[u][i]==1 && color[i] == -1){
                    color[i] = 1-color[u];
                    insert(i);
                }
                else if(G[u][i] == 1 && color[i] == color[u]){
                    return 0;
                }
            }

        }
        return 1;
    }

    int main(){
        // scanf("%d",&v);
        v = 4;
        int color[v];
        int G[4][4] = {{0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {1, 0, 1, 0}};
        
        printf("%d",isBipartile(G, 0,color));
    }
