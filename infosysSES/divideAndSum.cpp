#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    int x;
    int k;
    vector<int> arr;
    cin>>n;
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if((arr[i]+arr[j])%k==0){
                cnt ++ ;
            }
        }
    }
    cout << cnt<< endl;
}