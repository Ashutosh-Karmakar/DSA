#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    int k = 1;
        vector<vector<int>> ans(numRows);
        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1);
            ans[i][0] = 1;
            ans[i][i] = 1;
            for(int j = 1;j<i;j++){
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
}

int main(){
    vector<vector<int>> ans = generate(5);
    for(auto it:ans){
        for(int t:it){
            cout << t <<" ";
        }
        cout << endl;
    }
}