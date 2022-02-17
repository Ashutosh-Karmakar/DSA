#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(){
    string day;
    int n;
    int x;
    int ans;
    cin >> day;
    cin >> n;
    if(day == "mon"){
        x = 6;
    }
    else if(day == "tues"){
        x = 5;
    }
    else if(day == "wed"){
        x = 4;
    }
    
    else if(day == "thrus"){
        x = 3;
    }
    else if(day == "frid"){
        x = 2;
    }
    
    else if(day == "sat"){
        x = 1;
    }
    else if(day == "sun"){
        x = 0;
    }

    if(n-x >= 0){
        ans = 1;
        n = n-x;
        ans += n/7;
    }
    else{
        ans = 0;
    }
    cout << ans << endl;
}