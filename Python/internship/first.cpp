#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool sortByNumber(const string s1,const string s2){
    int n1 = stoi(s1.substr(3,s1.length()));
    int n2 = stoi(s2.substr(3,s1.length()));
    return n1 < n2;

    
}
int main(){
    vector<string> a = {"ab-1", "ab-021", "ab-201", "ab-011", "ab-12","ab-22"};
    cout << "Before sorting :" << endl;
    for(string s:a){
        cout << s << " ";
    }
    cout << endl;
    sort(a.begin(),a.end(),sortByNumber);
    cout << "\nAfter sorting :" << endl;
    for(string s:a){
        cout << s << " ";
    }
    cout << endl;

}