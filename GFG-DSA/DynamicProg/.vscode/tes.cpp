#include<iostream>
#include<string>
using namespace std;
int sum(int N){
    int sum = 0;
    while(N){
        sum += N%10;
        N = N/10;
    }
    return sum;
}

int superSolve(int N){
    int i = 0;
    if(N<10){
        return N;
    }
    return superSolve(sum(N));
}
int main(){
    int N = 123;
    int k = 3;
    int sum = 0;
    while(k--){
        sum += superSolve(N);
    }
    
    cout << superSolve(sum) << endl;
}