#include<iostream>
#include<vector>
using namespace std;

void subsequence(vector<int> arr){
    int N = arr.size();
    for(int i=0;i<(1<<N);i++){
        for(int j=0;j<N;j++){
            if((i&(1<<j)) != 0){
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}
int main(){
    vector<int> arr = {1,15,13,10};
    subsequence(arr);
}