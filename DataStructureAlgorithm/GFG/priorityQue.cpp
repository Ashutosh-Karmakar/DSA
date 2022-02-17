#include<iostream>
#include<queue>
#include<algorithm>
#include<math.h>


using namespace std;
pair<int,int> refe = {1,7};

bool func(pair<int,int> a,pair<int,int> b){
    double d = (pow(((a.first) - (refe.first)),2) + (pow((a.second) - (refe.second),2)) );
    double c = (pow(((b.first) - (refe.first)),2) + (pow((b.second) - (refe.second),2)) );
    return d < c;
}

int main(){
    // priority_queue<int,vector<int>,greater<>> q;
    // q.push(10);
    // q.push(20);
    // q.push(8);
    // cout << q.top() << endl;

    vector<pair<int,int>> points;
    points.push_back({4,5});
    points.push_back({7,3});
    points.push_back({2,4});
    points.push_back({8,6});
    points.push_back({1,8});

    

    sort(points.begin(),points.end(),func);

    for(pair <int,int> i:points){
        cout << i.first << " : " << i.second << " - " << (pow(((i.first) - (refe.first)),2) + (pow((i.second) - (refe.second),2)) )<< endl;
    }
    cout << endl;
}

