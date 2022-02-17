#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// vector<vector<int>> merge(vector<vector<int>>& intervals) {
//     vector<vector<int>> ans;
//     if(intervals.size() == 0) return ans;
//     sort(intervals.begin(),intervals.end());
//     // for(auto it:intervals){
//     //     cout << it[0] << " " << it[1] << endl;
//     // }
//     vector<int> temp = intervals[0];
//     for(int i=1 ; i<intervals.size() ; i++){
//         cout << " J " << temp[1] << intervals[i][0] << endl;
//         if(temp[1] >= intervals[i][0]){
//             temp[1] = max(temp[1],intervals[i][1]);
//         }
//         else if(temp[1] < intervals[i][0]){
//             ans.push_back(temp);
//             temp = intervals[i];
//         }
//     }
//     cout << "\n" << temp[1] << endl;
//     ans.push_back(temp);        
    
//     return ans;
// }
// int main(){
//     vector<int> arr1 = {1,4,7,8,10};
//     vector<int> arr2 = {2,3,9};
//     int m = arr1.size();
//     int n = arr2.size();
//     int i = 0;
//     int j = 0;
//     while(i<m){
//         if(arr1[i] > arr2[j]){
//             int temp = arr1[i];
//             arr1[i]  = arr2[j];
//             arr2[j]  = temp;
//             sort(arr2.begin(),arr2.end());
//         }
//         i++;
//     }
//     cout << "After sorting:" << endl;
//     for(int i:arr1){
//         cout << i << " ";
//     }
//     cout << endl;
//     for(int i:arr2){
//         cout << i << " ";
//     }
//     cout << "\nNEXT"<<endl;

//     vector<vector<int>> a = {{1,4},{0,2},{3,5}};
//     vector<vector<int>> k = merge(a);
//     for(auto i:k){
//         cout << i[0] << " " << i[1] << endl;
//     }
// }


  void bfs(vector<vector<char>> grid,int i,int j,int N,int M,vector<vector<bool>> &vis){
        int x[] = {1,-1, 0,0};//,-1,1,-1, 1};
        int y[] = {0, 0,-1,1};//, 1,1,-1,-1};
        vis[i][j] = true;
        for(int k=0;k<4;k++){
            if(i+x[k]<N && j+y[k]<M && i+x[k]>=0 && j+y[k]>=0){
                if(vis[i+x[k]][j+y[k]] == false && grid[i+x[k]][j+y[k]] == '1'){
                    bfs(grid,i+x[k],j+y[k],N,M,vis);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<bool>> vis(N,vector<bool>(M,false));
        int cnt = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(vis[i][j] == false && grid[i][j] == '1'){
                    cnt++;
                    // vis[i][j] = true;
                    bfs(grid,i,j,N,M,vis);
                }
            }
        }
        return cnt;
    }
    int main(){
        vector<vector<char>> grid = {{'1','1','0','0','0'},
                                     {'1','1','0','0','0'},
                                     {'0','0','1','0','0'},
                                     {'0','0','0','1','1'}} ;
        cout<< numIslands(grid);
    }