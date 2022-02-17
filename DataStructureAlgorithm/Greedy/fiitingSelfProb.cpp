#include<iostream>
#include<vector>
using namespace std;
int main(){
    int w = 24;
    int m = 3;
    int n = 5;
    int cntm = 0;
    int cntn = 0;
    if(w%(m+n) == 0){
        if(w%m == 0){
            w = 0;
            cntm += w/m;
        }
        else if(w%n == 0){
            w = 0;
            cntm += w/n;
        }
        else{
            
        }
        
    }
}