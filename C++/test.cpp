#include<iostream>
using namespace std;

int func(int x){
    return x;
}
double func(double x,int y=40){
    return x;
}


int main(){
    int x = 10;
    int y = 20;
    int &z = x;
    int &w = y;
    z = 1;
    w = 2;
    cout << x << "," << y << endl;
    cout << func(x) << " " << func(20.1,20) << endl;
}