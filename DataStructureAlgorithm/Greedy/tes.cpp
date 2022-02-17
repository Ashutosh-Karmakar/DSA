#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// int gcd(int a,int b){
//     if(b == 0){
//         return a;
//     }
//     return gcd(b,a%b);
// }

// int main(){
//     // int arr[] = {8,1,2,4,6,7,1};
//     // int n = 7;
//     // int maxi = arr[0];
//     // vector<bool> prime(maxi+1,true);
//     // prime[0] = false;
//     // prime[1] = false;
//     // for(int i=2;i<maxi;i++){
//     //     if(prime[i]){
//     //         for(int k = i*2;k<maxi;k+=i){
//     //             prime[k] = false;
//     //         }
//     //     }
//     // }
//     // int cnt = 0;
//     // for(int i=0;i<n;i++){
//     //     for(int j=i+1;j<n;j++){
//     //         if(arr[i] != arr[j] && prime[gcd(arr[i],arr[j])] == false){
//     //             cout << gcd(arr[i],arr[j]) << endl;
//     //             cnt ++;
//     //         }
//     //     }
//     // }
//     // cout << cnt << endl;

//     int arr[] = {2,4,6,8};
//     int l = 0;
//     int n = 4;
//     int i = 31;
//     int sum = 0;
//     vector<int> *adj = new vector<int>[n];
//     while(i>=0){
        
//         // cout << i << "-";
//         for(int k=0;k<n;k++){
//             if((arr[k]&(1<<i)) != 0){
//                 adj[i].push_back(arr[k]);
//                 // cout << arr[k] << " ";
//             }
            
//         }
//         // cout << endl;
//         i--;
//     }
//     for(i=0;i<n;i++){
//         cout << i <<"-";
//         for(int j:adj[i]){
//             cout << j << " ";
//         }
//         cout << endl;
//     }
//     unordered_map<int,int> m;
//     // for(int i=0;i<n;i++){
//     //     m[arr[i]] = 0;
//     // }
//     // bool flag = false;
//     // while(i>=0){
//     //     i--;
//     //     for(int k=0;k<n;k++){
//     //         if((arr[k]&(1<<i))!=0){
//     //             if(m[arr[k]] == 1){

//     //             }
//     //             else if(m[arr[k] == 0]){
//     //                 sum += (1<<i);
//     //                 m[arr[k]] = 1;
//     //             }
//     //         }
//     //         l++;
//     //     }
//     //     if(flag){
//     //         break;
//     //     }

//     // }
//     cout << sum << endl;



// }


int main(){
    int arr[] = {4,2,2,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;
    int cnt = 0;
    int x = 0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        x = (x^arr[i]);
        if(x == k){
            cnt ++;
        }
        if(m.count(x) != 0){
            cnt += m[x];
        }
        m[x]++;
    }
    cout << cnt << endl;
}