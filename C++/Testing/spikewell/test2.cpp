
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int func(){
    
    vector<int> arr = {1,2,4,6,4,3,1};
    int N = arr.size();
    bool inc = false;
    bool dec = false;
    for(int i = 0;i<N-1;i++){
        if(arr[i] <= arr[i+1]){
            if(dec == true){
                return i;
            }
            inc = true;
        }
        else{
            if(inc == true){
                return i;
            }
            dec = true;
        }
    }
    return -1;
}
int main(){
    cout << func() << endl;
}

