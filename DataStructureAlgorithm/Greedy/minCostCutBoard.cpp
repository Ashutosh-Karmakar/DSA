#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// bool comp(int x,int y){
//     return x>y;
// }
void minCost(int X[],int Y[],int m,int n){
    // sort(X,X+m,comp);
    // sort(Y,Y+n,comp);
    int totalCost = 0;
    int hr = 1;
    int vr = 1;
    int i = 0;
    int j = 0;
    int k = 1;
    
    // 4 3 2 1 1 
    // 4 2 1

    while(i<m-1 && j<n-1){
        if(X[i] >= Y[j]){
            totalCost += X[i]*hr;
            vr ++;
            i++;
        }
        else if(X[i] < Y[j]){
            totalCost += Y[j]*vr;
            hr++;
            j++;
        }   
    }
    int total = 0;
    while(i<m-1){
        total += X[i++];
    }
    totalCost += total*hr;
    total = 0;
    while(j<n-1){
        total += Y[j++];
    }
    totalCost += total*vr;
    cout << totalCost << endl;
}
int main(){
    int m = 6, n = 4;
    int X[] = {4, 3, 2, 1, 1};
    int Y[] = {4, 2, 1};
    minCost(X,Y,m,n);
}