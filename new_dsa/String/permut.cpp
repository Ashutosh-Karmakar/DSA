#include<iostream>
#include<string>
using namespace std;

void swap(string &s,int i,int j){
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void per(string str,int l,int r){
    if(l == r){
        cout << str << endl;
    }
    for(int i=l;i<=r;i++){
        swap(str,l,i);
        per(str,l+1,r);
        swap(str,i,l);
    }
}

int main(){
    string str = "XYZ";
    per(str,0,str.length()-1);
}