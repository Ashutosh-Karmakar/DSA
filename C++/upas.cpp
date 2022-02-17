#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<unordered_map>
#include <cctype>
#include<math.h>
using namespace std;
int main(){
    int n = 3;
    int arr[] = { 1,1,2,2,3,3};
    vector<pair<int,int>> cord;
    for(int i=0;i<n*2;i+=2){
        cord.push_back({arr[i],arr[i+1]});
    }
    for(auto it:cord){
        cout << it.first << " " << it.second << endl;
    }
    double m = (cord[1].second - cord[0].second)/(cord[1].first - cord[0].first);
    for(int i=2;i<n;i++){
        if((cord[i].second-cord[0].second)/(cord[i].first-cord[0].first) != m){
            return 0;
        }
    }
    
    int b = cord[0].second - (m*cord[0].first);
    int x = cord[1].second-cord[0].second;
    int y = cord[1].first-cord[0].first;
    string str =to_string(x) + "x" + " - "+ to_string(y) + "y " + "= " + to_string(b) ;
    cout << str << endl;

    
}