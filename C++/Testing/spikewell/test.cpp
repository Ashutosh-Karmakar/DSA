#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int main(){
    string s = "Passord1@";
    
    string s2 = s;
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    cout << s << endl;
    bool flag = false;
    if(s.length() >7 && s.length() < 31){
        flag = true;
    }
    if(flag == true){
        for(int i = 0;i< s2.length();i=i+8){
            string temp = s2.substr(i,i+8);
            if(temp == "password"){
                flag = false;
            }
        }
    }
    cout << flag << endl;
    bool temp = false;
    bool cap = false;
    bool num = false;
    bool pun = false;
    if(flag == true){
        for(int i =0;i<s.length();i++){
            if(s[i] >=48 && s[i] <= 57){
                num = true;
            }
            else if(s[i] >= 65 && s[i] <= 90){
                cap = true;
            }
            else if((s[i] >= 33 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 64) || (s[i] >= 91 && s[i] <= 96) || (s[i] >= 123 && s[i] <= 126)){
                pun = true;
            }
            // else {
            //     temp = false;
            // }
        }
    }
    if(num && pun && cap && flag){
        flag = true;
    }
    else {
        flag = false;
    }
    cout << flag << endl;


}
