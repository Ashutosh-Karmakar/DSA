#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include <string>



using namespace std;

int main(){
    vector<string> arr = {"12","32","/","*",""};
    stack<int> s;
    for(auto it:arr){
        if(it=="*" || it=="-" || it=="+" || it=="/"){
            int sec = s.top();
            s.pop();
            int fir = s.top();
            s.pop();
            if(it == "*"){
                s.push(fir * sec);
            }
            else if(it == "+"){
                s.push(fir + sec);
            }
            else if(it == "-"){
                if(sec == 0)continue;
                s.push(fir - sec);
            }
            else if(it == "/"){
                s.push(fir / sec);
            }
        }  
        else {
            s.push(stoi(it));
        }
    }
    cout << s.top() << endl;

}