#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void minCost(int X[],int Y[],int n,int m){
    sort(X,X+n,greater<int>());
    sort(Y,Y+m,greater<int>());
    int i=0;
    int j=0;
    int hr=1;
    int totalCost = 0;
    int vr=1;
    while(i< n && j< m){
        if(X[i] > Y[j]){
            totalCost += X[i] * vr;
            i++;
            hr++;
        }
        else{
            totalCost += Y[j]*hr;
            j++;
            vr++;
        }
    }
    int total = 0;
    while(i<n){
        total += X[i];
        i++;
        hr++;
    }
    totalCost += total*vr;
    total = 0;
    while(j<m){
        total += Y[j];
        j++;
        vr++;
    }
    totalCost += total*hr;
    cout << totalCost << endl;

}
int main(){
    int X[]={2,1,3,1,4};
    int Y[]={4,1,2};
    int n = 5;
    int m = 3;
    minCost(X,Y,n,m);
}