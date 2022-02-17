#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;

int main(){
    int n = 3;
    int k = 2;
    vector<int> arr;
    for(int i=1;i<=n;i++){
        arr.push_back(i);
    }
    vector<vector<int>> a;
    int m = 0;
    int h = pow(2,arr.size());
    vector<int> temp;
    bool f;
    int g = 0;
    for(int i=h-1;i>=0;i--){
        f = false;
        g = 0;
        temp.clear();
        for(int j = 0;j<arr.size();j++){
            if(i & (1<<j)){
                // cout << "g "<<g << " g ";
                if(g > 0 && ((arr[j] % temp[g-1]) == 0 )){
                    // cout << "bye ^" << arr[j] << "^  ^" << temp[g] << "  -- ";
                    f = true;
                }
                else if(g==0){
                    f = true;
                }
                else{
                    f=false;
                }
                temp.push_back(arr[j]);
                g++;
                cout << arr[j] << " ";    
            }
        }
        if(f){
            if(temp.size() == k){
            cout << "hellp " << endl;
            a.push_back(temp);
            }
        }
        m++;
        cout << endl;
    }
    cout << " size : " << m << endl;
    cout << "The output " << endl;
    for(vector<int> i:a){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
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