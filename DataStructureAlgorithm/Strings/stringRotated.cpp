#include<iostream>
#include<string>
#include<queue>
using namespace std;

bool function(string s1,string s2){
    int n = s1.length();
    queue<char> q1;
    queue<char> q2;
    for(int i=0;i<n;i++){
        q1.push(s1[i]);
        q2.push(s2[i]);
    }
    for(int i=0;i<n;i++){
        if(q1 == q2) return true;
        char a = q2.front();
        q2.pop();
        q2.push(a);
    }
    return false;

}
int main(){
    string s1 = "ABCD";
    string s2 = "CDAB";
    cout << function(s1,s2)<<endl;
}