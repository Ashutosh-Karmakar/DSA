#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){ 
    string s= "Hello World";
    cout << s << endl;
    int start = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' ' || i == s.length()-1){
            int end = (i == s.length()-1)?s.length():i;
            for(int j = start;j<(end+start)/2;j++){
                char temp = s[j];
                s[j] = s[end-j-1+start];
                s[end-j-1+start] = temp;
            }
            start = i+1;
        }
    }
    start = 0;
    s[start] = s[start]-32;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' ' || i+1 == s.length()){
            int end = (i==s.length()-1)?s.length():i;
            s[end-1] = s[end-1]+32;
            if(end != s.length())
                s[end+1] = s[end+1]-32;
        }
    }
    cout << s << endl;
}