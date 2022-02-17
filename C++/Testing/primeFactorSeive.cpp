#include<iostream>
#include<math.h>
#include<vector>
// #include<pair>
using namespace std;




void primeFactorization(int n){
    vector<int> v(n+1,0);
    v[1] = 1;
    for(int i=2;i<n+1;i++){
        if(v[i] == 0){
            v[i] = i;
        }
        for(int j=i*2;j<n+1;j+=i){
            if(v[j] == 0)
                v[j] = i;
        }
    }
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;
    while(n!=1){
        cout << v[n] << " ";
        n = n/v[n];
    }
    cout << endl;



}

int main(){
    int n;
    cout << "Enter a integer:" ;
    // cin >> n;
n = 144;
    cout << n  << " = " << endl;
    // while(n%2 == 0){
    //     cout << 2 << " " ;
    //     n = n/2;
    // }

    // for(int i=3;i<=sqrt(n);i++){
    //     while(n%i==0){
    //         cout << i << " ";
    //         n = n/i;
    //     }
    // }
    // cout << n << endl;
    primeFactorization(n);


}