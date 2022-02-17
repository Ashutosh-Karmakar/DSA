#include<iostream>
using namespace std;
int getBit(int n,int pos){
    return (n & (1<<pos)) != 0;
}
int setBit(int n,int pos){
    return (n | (1<<pos));
}
int clearBit(int n,int pos){
    int mask = ~(1<<pos);
    return (n & mask);
}
int updateBit(int n,int pos,int val){
    int mask = ~(1<<pos);
    int n1 = (n&mask);
    return (n1 | (val << pos));
}

int main(){
    int n = 5;
    cout << "GET: " << getBit(n,2) << endl;
    cout << "SET: " << setBit(n,1) << endl;
    cout << "CLEAR: " << clearBit(n,1) << endl;
    cout << "UPDATE: " <<updateBit(7,1,0) << endl;
    
    

}