#include<iostream>
#include<stack>

using namespace std;
int f = -1;
int c = -1;
class Node{
    public:
    int data;
    Node *left;
    Node *right;  

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};


Node *insert(Node *root,int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    if(root->data > data){
        root->left = insert(root->left,data);
    }
    else if(root->data < data){
        root->right = insert(root->right,data);
    }
    return root;
}

void ceilFloorFunc(Node *root,int k){
    if(root == NULL){
        return;
    }
    if(root->data == k){
        f = root->data;
        c = root->data;
        return;
    }
    else if(root->data > k){
        if(c==-1){
            c = root->data;
        }
        else{
            c = min(root->data,c);
        }
        ceilFloorFunc(root->left,k);
    }
    else if(root->data < k){
        if(f==-1){
            f = root->data;
        }
        else{
            f = min(root->data,c);
        }
        ceilFloorFunc(root->right,k);
    }
    

}

void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node *root = NULL;
    root = insert(root,7);
    root = insert(root,4);
    root = insert(root,13);
    root = insert(root,2);
    root = insert(root,6);
    root = insert(root,10);
    root = insert(root,14);
    root = insert(root,8);
    root = insert(root,11);

    cout << "\nThe tree inorder is :" << endl;
    inorder(root);
    cout << endl;

    int key = 12;
    ceilFloorFunc(root,key);
    cout << "f : "<< f << " | c : " << c << endl;

}