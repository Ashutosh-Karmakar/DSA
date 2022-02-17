#include<iostream>
#include<stack>

using namespace std;
stack<int> s;


void insert(int x){
    if(s.empty()){
        s.push(x);
    }
    else{
        int c = s.top();
        s.pop();
        if(x < c){
            insert(x);
            s.push(c);
        }
        else{
            s.push(c);
            s.push(x);
        }

    }

}

void Arraysort(){
    if(!s.empty()){
        int x = s.top();
        s.pop();
        Arraysort();
        insert(x);
    }
}
int main(){
    s.push(-1);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);
    cout << s.top() << endl;//-3
    Arraysort();
    cout << s.top() << endl;//18
    s.pop();
    cout << s.top() << endl;//14
    s.pop();
    cout << s.top() << endl;//-1
    s.pop();
    cout << s.top() << endl;//-3
    s.pop();
    cout << s.top() << endl;//-5

}
