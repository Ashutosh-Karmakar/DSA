#include<iostream>
#include<vector>
using namespace std;

int main(){
    int gas[] = {684, 57, 602, 987};
    int cost[] = {909, 535, 190, 976 };

    int n = 4;
    int r = 0;
    int f = 0;
    int rem = gas[0] - cost[0];
    int cnt = 0;
    while(true){  

        if(cnt > f || cnt == 2*n) break;
        cnt ++ ;
        if(rem<0){
            rem = 0;
            f=(f+1)%n;
            r = f;
        }
        r = (r+1)%n;
        rem = (gas[r]+rem) - cost[r];
    }
    if(cnt == 2*n) cout << -1 << endl;;
    cout << f+1 << endl;
}