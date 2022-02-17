#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;

int main(){
    int n = 2;
    int k = 2;
    vector<int> arr;
    for(int i=1;i<=n;i++){
        arr.push_back(i);
    }
    vector<int> a[100];
    int m = 0;
    for(int i=0;i<pow(2,arr.size());i++){
        for(int j = 0;j<arr.size();j++){
            if(i & (1<<j)){
                a[m].push_back(arr[j]);
                // cout << arr[j] << " ";    
            }
        }
        m++;
        // cout << endl;
    }
    
    // cout << " size : " << m << endl;
    int cnt = n;
    bool flag = true;
    for(int i=0;i<m;i++){
        if(a[i].size() == k){
            flag = true;
            for(int l=1;l<a[i].size();l++){
                if((a[i][l] % a[i][l-1]) != 0){
                    flag = false;
                }
                // cout << a[i][l-1] << " ";
            }
            if(flag){
                cnt ++;
            }
            // cout << endl;
        }
        
    }
    cout << endl;
    cout << cnt << endl;
}