#include<iostream>
using namespace std;
bool isPowerOf2(int n){
    if(n == 0) return false;
    return !(n&n-1);
}
int countOnes(int n){
    int cnt = 0;
    while(n!=0){
        n =(n & n-1);
        cnt ++ ;
    }
    return cnt;
}
void finSubsets(int arr[],int n){
    for(int i = 0 ; i<(1<<n) ; i++){
        for(int k = n-1 ;k>=0;k--){
            if((i&(1<<k))){
                cout << arr[k] << " ";
            }
        }
        cout << endl;
    }
}
int main(){
    int n = 8;
    cout << "Power Of 2: "<<isPowerOf2(n) << endl;
    cout << "Count Of !: "<<countOnes(7) << endl;
    int arr[] = {1,2,3};
    finSubsets(arr,3);
}