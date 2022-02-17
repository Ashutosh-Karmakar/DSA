// #include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>


using namespace std;


bool f(int x,int y){
    return x>y;
}

void vectorFunc(){
vector<int> v;
    v.push_back(1100);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(500);
    v.push_back(6);

    for(auto i=v.begin();i!=v.end();i++){
        cout << *i << " ";
    }
    cout<<endl;

    sort(v.begin(),v.end()); //O(Nlog(N))
    
    for(auto i=v.begin();i!=v.end();i++){
        cout << *i << " ";
    }
    cout<<endl;
    
    //2 3 4 6 500 1100

    bool present = binary_search(v.begin(),v.end(),500);
    cout<< present << endl;


    vector<int> :: iterator it = upper_bound(v.begin(),v.end(),500);
    cout << *it << endl;

    
    sort(v.begin(),v.end(),f); //O(Nlog(N))
    v.erase(v.end()-1);
    
    for(auto i=v.begin();i!=v.end();i++){
        cout << *i << " ";
    }
    cout<<endl;

}

void print(priority_queue<int> p){
    while(!p.empty()){
            cout << p.top() << " ";
            p.pop();
        }
        cout << endl;
}
int main(){
    vector<int> v(10);
    v[1] = 10;
    cout << v[1] << endl;
    for(int i=0;i<v.size();i++){
        cout<< v[i] << endl;
    }
}
