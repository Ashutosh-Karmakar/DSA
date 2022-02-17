#include<iostream>
#include<map>
#include<queue>

using namespace std;


class Node {
    public:
    int data;
    Node *left;
    Node *right;
    int hd;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root){
    if(root==NULL)return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void topView(Node *root){
    if(root==NULL) return;
    queue<Node*> q;
    multimap<int,int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        hd = temp->hd;
        // if(m.count(hd) == 0){
            m.insert(pair<int,int>(hd, temp->data));
        // }
        if(temp->left != NULL){
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if(temp->right != NULL){
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
    for(auto it = m.begin();it != m.end();it++){
        cout << it->second << " ";
    }

}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    cout << "The tree traversal: " << endl;
    inorder(root);
    cout << endl;

    cout << "Top View Of The Tree: " << endl;
    topView(root);
    cout << endl;
}