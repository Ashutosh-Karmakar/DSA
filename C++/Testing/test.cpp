#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    int n=12;
    for(int i=2;i<=sqrt(n);i++){
        if(n/i == i){
            cout << i << " ";
        }
        else{
            cout << i << " " << n/i << " ";
        }
    }
    cout << "\n";

}