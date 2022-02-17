#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int find(int A,vector<char> par){
    if(par[A] == (A)){
        return (A);
    }
    return par[A] = find(par[A],par);
}
void union_op(int f1,int f2,vector<char> &par,vector<int> &rank){
    if(rank[f1] > rank[f2]){
        par[f2] = f1;
    }
    else if(rank[f1] < rank[f2]){
        par[f1] = f2;
    }
    else{
        par[f2] = f1;
        rank[f1] += 1;
    }
}

int minOperations(string s1,string s2){
    vector<char> par(27);
    vector<int> rank(27);
    for(int i=1;i<=26;i++){
        par[i] = i;
        rank[i] = 0;
    }
    int i = 0;
    int cnt = 0;
    while(i<s1.length()){
        int f1 = find(s1[i]-96,par);
        int f2 = find(s2[i]-96,par);
        if(s1[i]!=s2[i]){
            if(f1 != f2){
                union_op(f1,f2,par,rank);
                cnt++;
            }
        }
        i++;
    }
    return cnt;
}
int main(){
    string s1 = "bab";
    string s2 = "aab";

    int s = minOperations(s1,s2);
    cout << s << endl;
}