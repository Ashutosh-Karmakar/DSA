#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void bfs(Node *root){
    queue<Node *> que;
    que.push(root);
    Node *temp;
    while(!que.empty()){
        int size = que.size();
        while(size--){
            temp = que.front();
            que.pop();
            cout << temp->data << " ";
            if(temp->left != NULL){
                que.push(temp->left);
            }
            if(temp->right != NULL){
                que.push(temp->right);
            }
        }
        cout << endl;
    }
}
int maxi = 0;
int diameter(Node *root){
    if(root == NULL){
        return 0;
    }
    int L = diameter(root->left);
    int R = diameter(root->right);
    maxi = max(maxi,L+R+1);
    return max(L,R)+1;
}
int findDiameter(Node *root){
    maxi = 0;
    diameter(root);
    return maxi;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->left = new Node(11);
    root->right->right = new Node(14);

    bfs(root);
    cout << findDiameter(root) << endl;

}