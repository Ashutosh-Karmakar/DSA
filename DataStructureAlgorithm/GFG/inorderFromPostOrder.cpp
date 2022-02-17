#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int id=0;
unordered_map<int,int> m;
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

Node* solve(int preorder[],int inorder[],int start,int end){
    if(start > end) return NULL;

    Node *node = new Node();
    node->data = preorder[id++];

    if(start == end) return node;
    int pos = m[node->data];
    cout << pos << endl;
    node->l = solve(preorder,inorder,start,pos-1);
    node->r = solve(preorder,inorder,pos+1,end);
    return node;
}

Node* arrayToTree(int preorder[],int inorder[],int n){
    m.clear();
    for(int i=1;i<n+1;i++){
        m[inorder[i]] = i;
    }
    for(int i=1;i<n+1;i++){
        cout << i << " :hello " << m[i] << endl;
    }
    Node *root = solve(preorder,inorder,0,n-1);
    return root;

}
void inorderTrav(Node *root){
    if(root==NULL){
        return;
    }
    inorderTrav(root->l);
    cout << root->data << "\t";
    inorderTrav(root->r);
}

int main(){
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    int N = 5;
    Node *root = arrayToTree(preorder,inorder,5);
    // cout << root -> data << endl;
    // cout << root -> l -> data << endl;
    cout << "The tree is ready : " << endl;
    inorderTrav(root);
    cout << endl;
   

}