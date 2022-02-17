#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *l;
    Node *r;
    Node(int d){
        data = d;
        l = NULL;
        r = NULL;
    }
};
bool isBST(Node *root,int start,int end){
    if(root==NULL){
        return true;
    }
    if(root->data >= start && root->data <= end){
        if(isBST(root->l,start,root->data) && isBST(root->r,root->data,end))
            return true;
        return false;
    }
    
    return false;
    
}
int main(){
    Node *root = new Node(3);
    root->l    = new Node(2);
    root->r    = new Node(5);
    root->l->l = new Node(1);
    root->l->r = new Node(4);
    if(isBST(root,INT_MIN,INT_MAX)){
        cout << "Is A BST" << endl;
    }
    else{
        cout << "Not A BST" << endl;
    }

}