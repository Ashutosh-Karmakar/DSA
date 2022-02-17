#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> ans;
vector<int> temp;
void solve(vector<int> can,int i,int t){
    // cout << "can :"<<can[i] << endl;
    // cout << "t: " << t << endl;
    if(i < 0 || i>=can.size()){
        return;
    }
    if(t < can[i] && t!=0){
        return;
    }
    if(t == 0){
        ans.push_back(temp);
        return;
    }
    temp.push_back(can[i]);
    solve(can,i,t-can[i]);
    temp.pop_back();
    solve(can,i+1,t);  
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    solve(candidates,0,target);
    return ans;
}
int main(){
    vector<int> a = {1,2,3,5,6,7};
    int target = 9;
    vector<vector<int>> b = combinationSum(a,target);
    for(auto it:b){
        for(int i: it){
            cout << i << " ";
        }
        cout << endl;
    }


}