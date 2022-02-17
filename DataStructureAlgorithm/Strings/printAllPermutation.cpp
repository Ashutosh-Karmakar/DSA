#include<iostream>
#include<string>
using namespace std;
int i = 0;
void swap(string &a,int i ,int j){
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void permutation(string a,int l,int r){
    if(l==r){
        cout << i++<<": "<< a << endl;
    }
    for(int i=l;i<=r;i++){
        swap(a,l,i);
        permutation(a,l+1,r);
        swap(a,l,i);
    }
}
int main(){
    string a = "abba";
    permutation(a,0,a.length()-1);
}