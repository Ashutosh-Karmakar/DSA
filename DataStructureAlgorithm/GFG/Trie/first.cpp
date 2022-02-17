#include<iostream>
#include<unordered_map>
using namespace std;
struct Trie{
    char data;
    unordered_map<char,Trie *> children;
    bool end = false;
};


void insert(Trie *root,string curr){
    Trie *temp = root;
    for(auto it:curr){
        if(temp->children[it] == NULL){
            Trie *t = new Trie;
            t->data = it;
            temp->children[it] = t;
        }
        temp = temp->children[it];
    }
    temp->end = true;
}

bool search(Trie *root,string s){
    for(auto it:s){
        if(root->children[it] != NULL){
            root = root->children[it];
        }
        else{
            return false;
        }
    }
    if(root->end == true) return true;
    else return false;
}



int main(){
    Trie *root = new Trie;
    insert(root,"ashu");
    insert(root,"anshu");
    insert(root,"ishu");

    cout << search(root,"anshu") << endl;

}
