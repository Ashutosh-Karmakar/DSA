#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void prime(unordered_map<int,bool> &primeArr){
    vector<bool> arr(1000000,true);
    arr[0] = false;
    arr[1] = false;
    for(int i=2;i<1000000;i++){
        if(arr[i] == true){
            for(int j=i*2;j<1000000;j = j+i){
                arr[j] = false;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        if(arr[i]){
            primeArr[i] = true;
        }
    }
}
int sum(int x){
    int sum = 0;
    if(x<10){
        return x;
    }
    else{
        while(x!=0){
            sum += x%10;
            x = x/10;
        }
        return sum;
    }
    return sum;
}
typedef struct PA{
    int x;
    int y;
    PA(int a,int b){
        x = a;
        y = b;
    }
} PA;


int main(){
    unordered_map<int,bool> primeArr;
    prime(primeArr);
    int n ;
    cin >> n;
    int cnt =0;
    unordered_map<PA *,int> check;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(primeArr.count(sum(i) + sum(j)) != 0){
                PA *p1 = new PA(i,j);
                PA *p2 = new PA(j,i);
                if(check.count(p1)==0 && check.count(p2)==0){
                    check[p1] = 1;
                    cnt ++;
                }
            }
        }
    }
    cout << cnt << endl;
    
}
