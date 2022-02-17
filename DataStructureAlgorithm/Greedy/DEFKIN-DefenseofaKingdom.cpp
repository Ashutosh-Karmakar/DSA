#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int solve(int arr[][2],int h,int w,int n){
    vector<int> row;
    vector<int> col;
    row.push_back(0);
    for(int i = 0;i<n;i++){
        row.push_back(arr[i][0]);
        col.push_back(arr[i][1]);
    }
    row.push_back(h+1);
    // for(int c:row){
    //     cout << c << " ";
    // }
    // cout << endl;
    
    int maxArea = -1;
    int i = 0;
    int j = 0;
    int area = 0;
    while(i<row.size()-1){
        j = 0;
        while(j<col.size()-1){
            area = abs(row[i+1]-row[i]-1)*abs(col[j]-col[j+1]-1);
            // cout << abs(col[j+1]-col[j]-1)   << endl;
            maxArea = max(maxArea,area);
            j++;
        }
        i++;
    }
    cout << maxArea << endl;
    return maxArea ;
}


int main(){
    int h = 15;
    int w = 8;
    int n = 3;
    int arr[][2] = {{3,8},
                    {8,6},
                    {11,2}};
    solve(arr,h,w,n);
}