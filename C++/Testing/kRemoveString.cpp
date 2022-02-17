#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string s = "geeksforgeeks";
    int k = 2;
    stack<pair<char,int>> st;
    st.push({s[0],1});
    for(int i=1;i<s.length();i++){
        if(s[i] == st.top().first){
            st.top().second++;
            if(st.top().second == k){
                while(st.top().first==s[i]){
                    st.pop();
                }
            }
        }
        else{
            st.push({s[i],1});
        }
    }
    while(!st.empty()){
        cout << st.top().first;
        st.pop();
    }
    cout << endl;
}