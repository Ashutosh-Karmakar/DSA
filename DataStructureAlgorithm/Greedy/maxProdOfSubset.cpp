#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int func(){
    int a[] = {-3,-2,-1,0};
    int n = 4;
    sort(a,a+n);
    int negC = 0;
    int zerC = 0;
    for(int i:a){
        if(i<0){
            negC++;
        }
        else if(i==0){
            zerC++;
        }
    }
    cout << negC <<" " << zerC << endl;
    int maxProd = 1;
    if(negC<=1){
        for(int i=n-1;i>=0;i--){
            if(a[i] >0)
                maxProd *= a[i];
        }
        return maxProd;
    }   
    else if(negC>1){
        for(int i=0;i<n-2;i=i+2){
            if(a[i] <0 && a[i+1] <0){
                maxProd *= a[i] * a[i+1];
            }
            else{
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(a[i] >0)
                maxProd *= a[i];
        }
        return maxProd;
    }
    return 0;
}
int main(){
    cout << func() << endl;
}