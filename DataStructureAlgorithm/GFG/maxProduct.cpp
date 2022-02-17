#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;


int maxProduct(vector<int> arr,int N,int i,int j,int k){
    if(i<0 || i>=N || j<0 || j>=N || k<0 || k>=N){
        return 1;
    }
    int n1 = maxProduct(arr,N,i,j,k+1);
    int n2 = maxProduct(arr,N,i,j+1,k);
    int n3 = maxProduct(arr,N,i+1,j,k);
    int n4 = maxProduct(arr,N,i,j+1,k+1);
    int n5 = maxProduct(arr,N,i+1,j,k+1);
    int n6 = maxProduct(arr,N,i+1,j+1,k);
    // int n7 = maxProduct(arr,N,i+1,j+1,k+1);

    int maxi = max(n1,max(n2,max(n3,max(n4,max(n5,n6)))));
    return maxi;
}




int main(){
    vector<int> a = {0,3,-70,-50,100,-1};
    int N = a.size();
    cout << maxProduct(a,N,0,1,2) << endl;
}