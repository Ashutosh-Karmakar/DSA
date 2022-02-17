#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *l,*r;
};
Node* newNode(int d){
    Node *new1 = new Node();
    new1->data = d;
    new1->l = NULL;
    new1->r = NULL;
    return new1;
}
bool findPath(Node *root, int k){
    if(root==NULL){
        return false;
    }
    if(root->data ==  k){
        return true;
    }
    if(findPath(root->l,k)||findPath(root->r,k)){
        cout << root->data << "\t";
        return true;
    }
    return false;
}
int main(){
    Node *root = newNode(8);
    root->l = newNode(7);
    root->r = newNode(6);
    root->l->l = newNode(10);
    root->l->r = newNode(11);
    root->r->l = newNode(12);
    root->r->l->l = newNode(14);
    // root->r->l->l->r = newNode(14);

    cout << "The diameter of the tree is :" << endl;
   
    

}