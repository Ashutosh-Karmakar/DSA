#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node *root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(root->data >= data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}
Node *inorderSuccesor(Node *root){
    while(root !=NULL && root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* deleteNode(Node *root,int data){
    if(root->data > data){
        root->left = deleteNode(root->left,data);
    }
    else if(root->data < data){
        root->right = deleteNode(root->right,data);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        else{
            Node *temp = inorderSuccesor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    return root;

}
void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
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

int main(){
    Node *root = NULL;
    root = insert(root,10);
    insert(root,20);
    insert(root,5);
    insert(root,3);
    insert(root,6);
    insert(root,12);
    insert(root,22);
    insert(root,24);
    insert(root,21);
    
    deleteNode(root,20);
inorder(root);
cout << endl;   
    bfs(root);
}