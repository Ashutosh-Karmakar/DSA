#include<iostream>
using namespace std;

int main(){
    int arr[] = {3,5,7};
    int cnt = 0;
    int div = 0;
    for(int i = 0;i< 3;i++){
        div = arr[i]/2;
        cnt += div;
        if(div%2 != 0){
            cnt += 1;
        }
    }
    cout << cnt << endl;
}