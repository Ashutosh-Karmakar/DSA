#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}
int main(){
    int arr[] = { 7, 10, 4};
    int n = 3;
    int k = 100;
    vector<pair<int,int>> stocks;
    for(int i= 0;i<n;i++){
        stocks.push_back({arr[i],i+1});
    }
    sort(stocks.begin(),stocks.end(),comp);
    int cost = 0;
    int cnt = 0;
    for(auto i:stocks){
        int count = i.second;
        while(count--){
            if(k<cost+i.first){
                break;
            }
            cout << i.first << endl;
            cnt ++;
            cost += i.first;
        }
    }
    cout << cnt << endl;
}