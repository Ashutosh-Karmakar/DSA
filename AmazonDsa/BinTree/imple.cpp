#include<iostream>
#include<queue>
#include<stack>
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

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void inorderNonRecur(Node *root){
    stack<Node *> nodes;
    Node *temp = root;
    while(!nodes.empty() || temp!=NULL){
        while(temp!=NULL){
            nodes.push(temp);
            temp = temp->left;
        }
        temp = nodes.top();
        nodes.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
}
void postorderNonRecur(Node *root){
    stack<Node *> nodes;
    Node *temp = root;
    while(temp != NULL || !nodes.empty()){
        while(temp != NULL){
            nodes.push(temp);
            temp = temp->left;
        }
        // if(temp && temp->right != NULL){
        //     temp = temp->right;
        // }
        // else{
            temp = nodes.top();
            nodes.pop();
            cout << temp->data << " ";
            temp = nodes.top();
            if(temp->right != NULL){
                temp = temp->right;
            // }
        }
                                      
    }
}

void preorderNonRecur(Node *root){
    stack<Node *> nodes;
    Node *temp = root;
    while(temp != NULL || !nodes.empty()){
        while(temp != NULL){
            nodes.push(temp);
            cout << temp->data << " ";
            temp = temp->left;
        }
        temp = nodes.top();
        nodes.pop();
        temp = temp->right;
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->left = new Node(11);
    root->right->right = new Node(14);

    // bfs(root);
    // cout << endl;
    // inorder(root);
    // cout <<"\n"<<"None recursive:" <<endl;
    // inorderNonRecur(root);
    preorderNonRecur(root);


}