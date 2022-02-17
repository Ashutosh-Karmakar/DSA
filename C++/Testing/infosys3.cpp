#include<iostream>
using namespace std;
int main(){
    int n = 2;
    int m = 2;
    int arr1[] = {2,6};
    int arr2[] = {24,36};
    int ans = 0;
    for(int i = 1;i<101;i++){
        bool flag = true;
        for(int j = 0;j<n;j++){
            if(i%arr1[j]!=0){
                flag = false;
            }
        }
        for(int j = 0;j<m;j++){
            if(arr2[j] % i!=0){
                flag = false;
            }
        }
        if(flag) ans++;
    }
    cout << ans << endl;
}