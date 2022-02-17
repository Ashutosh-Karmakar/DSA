#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int n = 5;
    // int *f = new int(n+2);
    // f[0] = 0;
    // f[1] = 1;
    // for(int i=2;i<n+2;i++){
    //     f[i] = f[i-1] + f[i-2];
    // }
    // cout << f[n] << endl;
    // int a = 0;
    // int b = 1;
    // cout << a << " " << b << " ";
    // for(int i=2;i<n+1;i++){
    //     cout << a+b <<" ";
    //     int c = a+b;
    //     a = b;
    //     b = c;
    // }

    // cout << gcd(5,12) << endl;
    int a = 0;
    int b = 12;
    if(a==0){
        cout << b<< endl;
        exit(0);
    }
    else if(b == 0){
        cout << a << endl;
        exit(0);
    }
    while(a!=b){
        if(a>b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    cout << a << endl;  
}