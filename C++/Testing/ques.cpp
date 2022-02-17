#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printSubsequence(int arr[],int size){
    vector<vector<int>> subset;
    for(int i=0;i<pow(2,size);i++){
        vector<int> v;
        for(int j=0;j<3;j++){
            if(((i) & (1<<j))){
                v.push_back(arr[j]);  
            }    
        }
        subset.push_back(v);
    }
    for(auto i:subset){
        if(i.size() == 0){cout << 0 << endl;continue;}
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
}


int main(){
    int arr[] = {15,10,3};
    int size = 3;
    for(auto j:arr){
        cout << j << " ";
    }
    cout << endl;
    // printSubsequence(arr,size);
    vector<int> v(10);
    v[0] = 100;
    cout << v[0] << endl;

}