#include<iostream>
#include<unordered_map>
using namespace std;
struct Node{
    char data;
    unordered_map<char,Node *> children;
    bool end;
    Node(char c){
        data = c;
        end = false;
    }
};
void insert(Node *root,string str){
    Node *temp = root;
    for(int i=0;i<str.length();i++){
        if(temp->children.count(str[i]) == 0){
            Node *child = new Node(str[i]);
            temp->children[str[i]] = child;
        }       
        temp = temp->children[str[i]];
    }
    temp->end = true;
}
int find(Node *root,string str){
    Node *temp = root;
    for(auto it:str){
        if(temp->children.count(it) == 1){
            temp = temp->children[it];
        }
        else{
            return 0;
        }
    }
    if(temp->end == true)
        return 1;
    return 0;
}


int main(){
    Node *root = new Node('-');
    insert(root,"hello");
    insert(root,"hi");
    insert(root,"helvetica");
    cout << find(root,"hello") << endl;
    cout << find(root,"helvetica") << endl;
}