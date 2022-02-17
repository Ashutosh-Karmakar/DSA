#include<iostream>
#include<map>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
// #include <bits/stdc++.h>
using namespace std;
int main(){
            //   0 1 2 3 4 5 6 7 8 9
    // int arr[] = {1,2,2,2,3,3,3,4,2,1};
                     
    // int N = 10;
    // map<int,int> m;
    // m[arr[0]] = 1;
    // int temp = 0;
    // int cur = arr[0];
    // // cout << "temp" << " " << "cur"<< " " << "arr[i]"<< " " << "i"<< endl;;
    // for(int i=1;i<N;i++){
    //     // cout << temp << endl;
    //                 // cout << arr[i] << endl;
    //     // cout << temp << " " << cur<< " " << arr[i]<< " " << i<< endl;;

    //     if(cur!=arr[i]){
    //         if(m.count(arr[i]) == 0){
    //             m[arr[i]] = 1;
    //         }
    //         else{
    //             m[arr[i]] += 1;
    //         }
    //         cur = arr[i];
    //         temp = i;
    //     }
    //     else if(cur == arr[i] && temp+1 != i){
    //         // cout << arr[i] << endl;
    //         m[arr[i]] += 1;
    //         temp = i;
    //         cur = arr[i];
    //     }
    // }
    // for (auto itr = m.begin(); itr != m.end(); itr++) {
	
	// 	cout << itr->first << '\t' << itr->second << '\n';
	// }

    // vector<int> order = {2,4,6,2,5};
    // int mini = 9999;
    // int num = -1;
    // int k = 0;
    // vector<vector<int>> marking = {{4, 10},{5, 7,10}};// 9}, {3, 5, 6}};
    
    // for(auto it:marking){
    //     int loss = 0;
    //     // cout << *max_element(order.begin(),order.end()) << " " << *max_element(it.begin(),it.end()) << endl;
    //     if(*max_element(order.begin(),order.end()) <= *max_element(it.begin(),it.end())){
    //         for(int i:order){
    //             for(int j:it){
    //                 if(j >= i){
    //                     // cout << j << " " << i << "= " << loss<< endl;
    //                     loss += j-i;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     else{
    //         loss = 999999;
    //     }
    //     // cout << mini << " " << loss << endl;
    //     if(mini >= loss){
    //         mini = loss;
    //         num = k;
    //     }
    //     k++;
    // }
    // cout << mini << endl;
    // cout << num << endl;

    map<char,int> m;
    m['A'] = 1;
    m['B'] = 3;
    m['C'] = 12;
    vector<char> res;
    int n = 20;
    auto j = m.end();
    j--;
    // cout << j->second << endl;
    while(true){
        if(n==0) break;
        if(n >= j->second){
            res.push_back(j->first);
            n = n - j->second;
            j = m.end();
            j--;
        }
        else{
            j--;
        }
    }
    for(auto i:res){
        cout << i << " ";
    }
    cout << endl;
}