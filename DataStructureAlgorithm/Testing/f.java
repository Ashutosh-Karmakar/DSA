import java.util.*;
class A{
    int n;
    ArrayList<Integer> edge[];
    A(int n){
        this.n = n;
        edge =new ArrayList[n+1]  ; 
        for(int i=0;i<n;i++){
            edge[i] = new ArrayList<>();
        }
    }
    public static void main(String args[]){
        A a = new A(5);
        a.addedge(1,2);
        a.addedge(1,3);
        a.addedge(3,2);
        a.addedge(2,4);
        a.addedge(3,4);
        
        a.longestEdge();
    }

    void addedge(int x,int y){
        edge[x].add(y);
    }
    void longestEdge(){
        boolean visited[] = new boolean[n+1];
        int dp[] = new int[n+1];
        for(int i=0;i<=n;i++){
            visited[i] = false;
        }
        for(int i=1;i<=n;i++){
            if(visited[i] != true)
                dfs(dp,visited,i);  
        }
        int ans = 0;
        System.out.println("here :" + dp[0]);
        for(int i:dp){
            System.out.println(i);
        }
    }
    void dfs(int dp[],boolean visited[],int node){
        visited[node] = true;
        for(int i=0;i<edge[node].size();i++){
            if(visited[edge[node].get(i)] == false){
                dfs(dp,visited,edge[node].get(i));
            }
            dp[node] = Math.max(dp[node] , 1 + dp[edge[node].get(i)]);

        }
    }
   
}