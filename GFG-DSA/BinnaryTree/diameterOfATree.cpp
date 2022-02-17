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
int maxi = 0;
int diameter(Node *root){
    if(root==NULL){
        return 0;
    }
    int L = diameter(root->l);
    int R = diameter(root->r);
    maxi = max(maxi,L+R+1);
    return max(L,R)+1;
}
int findDiameter(Node *root){
    maxi = 0;
    diameter(root);
    return maxi;
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
    cout << findDiameter(root) << endl;
    

}