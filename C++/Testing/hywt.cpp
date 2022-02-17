#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int> a,int s){
    int i = 0;
    int sum = 0;
    int nmax = 0;
    unordered_map <int,int> m;
    while(i<a.size()){
        sum = sum + a[i];
        if(sum == s){
            nmax = max(nmax,i+1);
        }
        else if(m.count(sum - s) != 0){
            nmax = max(nmax,i-m[sum-s]);
        }
        if(m.count(sum)==0){
            m[sum] = i;
        }
        i++;
    }
    return nmax;
}




int main(){
    vector<int> a = {1,6,3,2,1,5,1,12,8,4,8,3};
    int sum = 0;
    for(int i = 0;i<a.size();i++){
        sum = sum+a[i];
    }
    // vector<int> a = {1,2,3,4,5,1,1,1,1,1};

    int amt = 35;
    // if(sum < amt) return -1;
    cout << a.size()-solve(a,sum-amt);
    
    
}
































// void fun(){
//     int N = 9;
//     int M = 10;
//     vector<int> a = {1,2,2,2,3,8,8,9,10};
//     map<int,int> m;
//     for(int i = 0;i<M;i++){
//         m[i+1] = 0;
//     }
//     for(int i = 0;i<a.size();i++){
//             m[a[i]]++;
//     }
//     for(int i=0;i<M;i++){
//         cout << i+1 << "-" << m[i+1] << endl;
//     }


//     int cnt = 0;
//     for(auto it:m){
//         if(it.second==3){
//             cnt++;
//         }
//     }
//     for(int i=0;i<M-2;i++){
//         if(m[i+1] != 0 && m[i+2]!=0 && m[i+3]!=0){
            
//             cnt ++;
//         }
//     }
//     cout << cnt << endl;
// }