#include<iostream>
using namespace std;
#include<stack>
int main(){
    string s = "Hello this is ashu tosh karmakar." ;
              //this Hello.ashu is.karmakar tosh.
    stack<string> Stack;
    cout << s << endl;
    string rev;
    string temp ;
    // for(char c:s){
    //     if(c == ' '){
    //         // cout << temp << endl;
    //         Stack.push(temp);
    //         Stack.push(" ");
    //         temp.clear();
    //         continue;
    //     }
    //     else if(c == '.'){
    //         Stack.push(temp);
    //         temp.clear();
    //         while(!Stack.empty()){
    //             rev += Stack.top();
    //             Stack.pop();
    //         }
    //         rev += '.';
    //     }
    //     else{
    //         temp = temp + c;
    //     }
    //     // cout << c << endl;

    // }
    
    // int start = i;
    // int i=s.length()-1;
    // int end = i+1;
    // for(int i=s.length()-1;i>=0;i--){
    //     // start = i;
    //     if(s[i] == ' '){
    //         for(int j=i+1;j<end;j++){
    //             rev += s[j];
    //         }
    //         rev += ' ';
    //         end = i;
    //     }
    // }
    // for(int i = 0;i<end;i++){
    //     rev += s[i];
    // }
    
    int end = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            for(int j = i-1;j>=end;j--){
                rev += s[j];
            }
            rev += ' ';
            end = i+1;

        }
    }
    int i=s.length()-1;
    while(s[i] != ' '){
        rev += s[i--];
    }

    cout << rev << endl;

}