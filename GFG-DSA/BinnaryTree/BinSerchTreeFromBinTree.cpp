#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> inor;

class Node{
    public:
    Node *left;
    Node *right;
    int data;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }

};

void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    inor.push_back(root->data);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void create(Node *root,int &i){
    if(root == NULL) return;
    create(root->left,i);
    root->data = inor[i++];
    create(root->right,i);
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(4);


    cout << "The inorder Traversal : " << endl;
    inorder(root);
    cout << endl;
    cout << "The preorder Traversal: " << endl;
    preorder(root);
    cout << endl;


    cout << "Inside Array: " << endl;
    for(int i:inor){
        cout << i << " ";
    }
    cout << endl;

    sort(inor.begin(),inor.end());
    cout << "Inside Array After sort: " << endl;
    for(int i:inor){
        cout << i << " ";
    }
    cout << endl;
    int i = 0;
    create(root,i);

    cout << "The inorder Traversal After creation of tree again: " << endl;
    inorder(root);
    cout << endl;

    cout << "The preorder Traversal After creation of tree again: " << endl;
    preorder(root);
    cout << endl;
}