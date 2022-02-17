#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
};
Node* newnode(int d){
    Node *new1 = new Node();
    new1->data = d;
    new1->left = NULL;
    new1->right = NULL;
    return new1;
}

bool ancestor(Node *root , int d){
    if(root==NULL) return false;
    if(root->data == d) return true;
    if(ancestor(root->left,d) || ancestor(root->right,d)){
        cout << root->data << "\t";
        return true;
    }
    return false;
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}

int main(){
Node *root = newnode(11);
  root->left              = newnode(2);
  root->right             = newnode(3);
  root->left->left        = newnode(4);
  root->left->right       = newnode(5);
  root->left->left->left  = newnode(7);
  cout << "The tree inorder is :" << endl;
  inorder(root);
  cout << endl;

  int d = 5;
  cout << "The ancestor of " << d << " is : " << endl;
  ancestor(root,d);
  cout << endl;
}