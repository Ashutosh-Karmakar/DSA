#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int sortFunc(pair<int,int> &a,pair<int,int> &b){
    return a.first < b.first;
}

int main(){
    int arr[] = {2,123,78,130,10,0};
    int n = arr[0];
    int ex = arr[1];
    vector<pair<int,int>> p;
    for(int i=2;i<n+2;i++){
        p.push_back({arr[i],arr[i+n]});
    }
    for(int i=0;i<n;i++){
        cout << p[i].first << " : " << p[i].second << endl;
    }

    sort(p.begin(),p.end(),sortFunc);

    cout << "After sorting : " << endl;
    for(int i=0;i<n;i++){
        cout << p[i].first << " : " << p[i].second << endl;
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        if(ex >= p[i].first){
            cnt ++ ;
            ex += p[i].second;
        }
    }
    cout << "The final answer is : "<< endl;
    cout << cnt << endl;

}
