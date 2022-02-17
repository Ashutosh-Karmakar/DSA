#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,0,3,2};
    

    int arr2[4];
    for(int i=0;i<4;i++){
        arr2[i] = arr[i] - i;
    }
    int pos = 0;
    int neg = 0;
    int cnt = 0;
    for(int i=0;i<4;i++){
        if(arr2[i] < 0){
            neg ++;
            cnt += pos;
        }
        else if(arr2[i] >=0){
            pos ++;
            cnt += neg;
        }
    }
    cout << cnt  << endl;
}
