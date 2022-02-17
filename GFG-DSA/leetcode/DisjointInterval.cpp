#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
static bool comp(vector<int> a,vector<int> b){
    return (abs(a[0]-a[1]) < abs(b[0]-b[1]));
}
int solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end(),comp);
    int cnt = 1;
    int s = A[0][0];
    int e = A[0][1];
    for(auto it:A){
        for(int i:it){
            cout << i << " ";
        }
        cout << endl;
    }
    for(int i = 1;i<A.size();i++){
        if((A[i][0] > s && A[i][1] >e) || (A[i][0] < s && A[i][1] < e)){
            cnt ++;
        }
    }
    return cnt;
}
int main(){
    vector<vector<int>> A = {{3, 13},
                             {7, 7},
                             {3, 10},
                             {4, 8},
                             {7, 8},
                             {9, 12},
                             {3, 6},
                             {7, 12},
                             {4, 10},
                             {3, 8},
                             {5, 11},
                             {9, 10},
                             {3, 7},
                             {4, 4},
                             {7, 15},
                             {2, 9}};
    solve(A);
    
}