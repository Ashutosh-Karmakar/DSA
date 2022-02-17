#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<char> temp;
void findSubseq(string s,int start){
    if(start >= s.length()){
        for(char c:temp){
            cout << c ;
        }
        cout << endl;
        return;
    }
    temp.push_back(s[start]);
    findSubseq(s,start+1);
    temp.pop_back();
    findSubseq(s,start+1);
    return;

}
int main(){
    string s = "abc";
    findSubseq(s,0);
}