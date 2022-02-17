#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> ans;

void subSequence(int arr[],int N,vector<int> &temp,int index){
    if(index == N){
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[index]);
    subSequence(arr,N,temp,index+1);
    temp.pop_back();
    subSequence(arr,N,temp,index+1);
}

int main(){
    int arr[] = {10,9,6};
    int N = 3;
    vector<int> temp;
    subSequence(arr,N,temp,0);
    cout << "The subsequences are :" << endl;
    for(auto it:ans){
        for(int i:it){
            cout << i << " ";
        }
        cout << endl;
    }
}