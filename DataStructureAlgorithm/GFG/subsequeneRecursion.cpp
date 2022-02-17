#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > subseq;
// int subSequence(vector<int> arr,int index,vector<bool> &visited,int N){
    // if(index == N){
    //     return 0;
    // }
    // if(index >0 && index <N-1 && !visited[index-1] && visited[index+1]){
    //     visited[index] = true;
    //     int sum1 = arr[index]+subSequence(arr,index+1,visited,N);
    //     visited[index] = false;
    //     int sum2 = subSequence(arr,index+1,visited,N);
    //     return max(sum1,sum2);
    // }
    // else if(index == 0 && !visited[index+1]){
    //     visited[index] = true;
    //     int sum1 = arr[index]+subSequence(arr,index+1,visited,N);
    //     visited[index] = false;
    //     int sum2 = subSequence(arr,index+1,visited,N);
    //     return max(sum1,sum2);
    // }
    // else if(index == N-1 && !visited[index-1]){
    //     visited[index] = true;
    //     int sum1 = arr[index]+subSequence(arr,index+1,visited,N);
    //     visited[index] = false;
    //     int sum2 = subSequence(arr,index+1,visited,N);
    //     return max(sum1,sum2);
    // }
    
// }
int main(){
    vector<int> arr = {10,9,6,11,8,13,14,12,16};

}


// cnt = 0;
int fun(int N,int step){
    if(step >= N){
        return 0;
    }
    return(fun(N,step+1)+fun(N,step+2));
}