#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int GCD(int a,int b){
    if(a == 0){
        return b;
    }
    if(b==0){
        return a;
    }
    if(a>b){
        return GCD(a-b,b);
    }
    return GCD(a,b-a);  
}
void prime(){
    bool arr[100];
    arr[0] = false;
    arr[1] = false;
    for(int i = 2;i<100;i++){
        arr[i] = true;
    }
    for(int i= 2;i<100;i++){
        if(arr[i] == true){
            int k = i*2;
            for(;k<100;k=k+i){
                arr[k] = false;
            }
        }
    }
    vector<int> primeA;
    for(int i=0;i<100;i++){
        if(arr[i] == true){
            primeA.push_back(i);
        }
    }
    for(int i:primeA){
        cout << i << " ";
    }
    
    cout << endl;
    cout << "The prime factors of 10:" << endl;
    for(int i=0;i<sqrt(24);i++){
        if(24%primeA[i]==0){
            cout << primeA[i] << " ";
        }
    }
    cout << endl;
}

int main(){
    int x = 15;
    int y = 35;
    cout << GCD(x,y) << endl;
    prime();
}