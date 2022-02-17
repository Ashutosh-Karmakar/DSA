#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int solve(int arr[],int n){
    vector<pair<int,int>> buy;
    vector<pair<int,int>> sell;
    for(int i=0;i<n;i++){
        if(arr[i] < 0){
            sell.push_back({i,arr[i]});
        }
        else{
            buy.push_back({i,arr[i]});
        }
    } 
    int i = 0;
    int j = 0;
    int cost = 0;
    while(i<buy.size() && j<sell.size()){
        int mini = min(buy[i].second,-sell[i].second);
        buy[i].second = buy[i].second - mini;
        sell[i].second = sell[i].second + mini;
        int x = abs(buy[i].first - sell[i].first);
        cost += mini*x;
        if(buy[i].second == 0)i++;
        if(sell[i].second == 0)j++;
    }
    return cost;
}

int main(){
    int arr[] = {5,-4,1,-3,1};
    int n = 5;
    cout << solve(arr,n) << endl;;

}