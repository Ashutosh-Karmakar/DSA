import java.util.Scanner;
/////////////////////DO AGAIN
class A{
    int v;
    int[] color;
    int[] arr;
    int front = -1;
    int rear = -1;
    A(int ver){
        v = ver;
        color = new int[v];
        arr = new int[200];
    }
    void insert(int k){
        if(front == -1){
            front++;
        }
        arr[++rear] = k;
    }

    int pop(){
        return arr[front++];
    }

    boolean isBipartile(int G[][],int x){
        for(int i=0;i<v;i++){
            color[i] = -1;
        }
        insert(x);
        while(front!= rear +1){
            int u = pop();
            
            if(G[u][u] == 1){
                return false;
            }
            
            for(int i=0;i<v;++i){
                if(G[u][i]==1 && color[i] == -1){
                    color[i] = 1-color[u];
                    insert(i);
                }
                else if(G[u][i] == 1 && color[i] == color[u]){
                    return false;
                }
            }

        }
        return true;
    }

    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int G[]
        int G[][] = {{0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {1, 0, 1, 0}};
        A a = new A(4);
        System.out.println(a.isBipartile(G, 0));
    }
}