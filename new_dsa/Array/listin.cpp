#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    for(auto it:l){
        cout << it << " ";
    }
    cout << endl;
    auto it = l.begin();
    advance(it,2);
    l.erase(it);
    cout << l.size() << endl;
    for(auto it:l){
        cout << it << " ";
    }
    
    
    
}

