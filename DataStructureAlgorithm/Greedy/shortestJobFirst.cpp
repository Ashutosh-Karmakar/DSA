#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
bool comp (vector<int> a,vector<int> b){
    if(a[1] == b[1]){
        if(a[2] < b[2]){
            return true;
        }
        else if(a[2] == b[2] && a[0] < b[0]){
            return true;
        }
    }
    return a[1] < b[1];
}
void sequence(vector<vector<int>> jobs){
    sort(jobs.begin(),jobs.end(),comp);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({jobs[0][2],jobs[0][1],jobs[0][0]});
    vector<int> ans;
    int curTime=0;
    int i = 1;
    while(!pq.empty()){
        int burstTime = pq.top()[0];
        int id = pq.top()[2];
        ans.push_back(id);
        curTime += burstTime;
        pq.pop();
        while(i<jobs.size() && jobs[i][1] <= curTime){
            pq.push({jobs[i][2],jobs[i][1],jobs[i][0]});
            i++;
        }
    }
    for(int i: ans){
        cout << i << " ";
    }
    cout << endl;
    return ;
}


int main(){
    vector<vector<int>> jobs;
    jobs.push_back({1,2,3});
    jobs.push_back({2,0,4});
    jobs.push_back({3,4,2});
    jobs.push_back({4,5,4});
    sequence(jobs);

}