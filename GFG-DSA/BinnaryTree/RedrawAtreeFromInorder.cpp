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
    for(int i=0;i<n;i++){
        m[inorder[i]] = i;
                cout << " m : " << inorder[i] << endl;

    }
    for(int i=0;i<n;i++){
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
    int preorder[] = {1,2,3};
    int inorder[] = {2,1,3};
    int N = 3;
    Node *root = arrayToTree(preorder,inorder,N);
    // cout << root -> data << endl;
    // cout << root -> l -> data << endl;
    cout << "The tree is ready : " << endl;
    inorderTrav(root);
    cout << endl;
   

}