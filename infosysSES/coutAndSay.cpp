#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 6;
    int k = 1;
    int cur = 1;
    vector<vector<int>> res;
    vector<int>temp;
    temp.push_back(1);
    res.push_back(temp);
    while(k<=n){
        int count = 1;
        int i = 0;
        temp.clear();
        while(i<res[k-1].size()){
            if(i+1 < res[k-1].size() && res[k-1][i] == res[k-1][i+1]){
                count ++;
            }
            else{
                cout << " " << count << " " << res[k-1][i]; 
                temp.push_back(count);
                temp.push_back(res[k-1][i]);
                count = 1;
            }
            i++;
        }
        res.push_back(temp);
        cout << endl;
        k++;
    }
}