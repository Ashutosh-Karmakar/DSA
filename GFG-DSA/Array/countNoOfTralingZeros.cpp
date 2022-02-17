#include<iostream>
using namespace std;
int main(){
    int n = 24;
    int i = 5;
    int cnt = 0;
    for(; n/i>=1; i*=5){
        cnt += n/i;
    }
    cout << cnt << endl;
}