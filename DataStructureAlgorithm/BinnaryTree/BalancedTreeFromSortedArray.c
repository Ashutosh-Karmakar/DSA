#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct BST{
    int key;
    struct BST *left,*right;
}BST;

BST* createBST(int k){
    BST *temp = (BST*)malloc(sizeof(BST));
    temp->key = k;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void inorder(BST* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->key);
    inorder(root->right);
}
void preorder(BST* root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->key);
    preorder(root->left);
    preorder(root->right);
}

BST* arrayToBst(BST *root,int start,int end,int arr[]){
    if(start>end) return NULL;
    int mid = (start+end)/2;
    BST *node = (BST*)malloc(sizeof(BST));
    node->key = arr[mid];
    node->left = NULL;
    node->right = NULL;
    root = node;
    root->left = arrayToBst(root->left,start,mid-1,arr);
    root->right = arrayToBst(root->right,mid+1,end,arr);
    return root;
}
int main(){
    

    BST* root = NULL;
    
    int arr[] = {1,2,3,4,5};
    int N = 5;
    root = arrayToBst(root,0,N-1,arr);
 
    printf("\nInOrder :\n");
    inorder(root); 
    printf("\nPreOrder :\n");
    preorder(root);  
}
