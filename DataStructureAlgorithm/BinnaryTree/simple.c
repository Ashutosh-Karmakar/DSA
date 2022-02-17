#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int key;
    struct Node *left,*right;
}Node;

Node* createNode(int k){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->key = k;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->key);
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->key);
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->key);
}


Node* insertRight(Node* root,int k){
    root->right = createNode(k);
}
Node* insertLeft(Node* root,int k){
    root->left = createNode(k);
}

int main(){
    Node* root = createNode(1);
    insertLeft(root,3);
    insertRight(root,4);
    printf("\nPreOrder :\n");
    preorder(root);  
    printf("\nInOrder :\n");
    inorder(root);  
    printf("\nPostOrder :\n");
    postorder(root);  
}
