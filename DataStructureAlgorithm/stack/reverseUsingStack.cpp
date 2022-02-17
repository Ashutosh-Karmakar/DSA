#include<iostream>
#include<stack>

using namespace std;
stack<int> s;
stack<int> s2;

void insert(int x){
    if(s.empty()){
        s.push(x);
    }
    else{
        int c = s.top();
        s.pop();
        insert(x);
        s.push(c);
    }

}

void rev(){
    if(!s.empty()){
        int x = s.top();
        s.pop();
        rev();
        insert(x);
    }
    
}

int main(){
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << s.top() << endl;
    rev();
    s.pop();
    cout << s.top() << endl;
}