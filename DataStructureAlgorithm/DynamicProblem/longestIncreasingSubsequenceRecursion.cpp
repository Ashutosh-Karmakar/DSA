#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int longestIncreasing(vector<int> arr,int prev,int index){
    if(index >= arr.size()){
        return 0;
    }
    if(prev == -1){
        return max(1+longestIncreasing(arr,index,index+1),longestIncreasing(arr,prev,index+1));
    }
    if(arr[index] <= arr[prev]){
        return longestIncreasing(arr,prev,index+1); 
    }
    else{
        return max(1+longestIncreasing(arr,index,index+1),longestIncreasing(arr,prev,index+1));
    }
    
}
int main(){
    vector<int> arr = {10,9,6,11,12,14,18,2,9};
    cout << "Hello" << endl;
    cout << longestIncreasing(arr,-1,0) << endl;
}