#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct BST{
    int key;
    struct BST *left,*right;
}BST;
int f = -1;
int r = -1;
BST* que[max];
void push(BST *x){
    if(f == -1)f++;
    que[++r] = x;
}
BST* pop(){
    return que[f++];
}
int queSize(){
    return r-f+1;
}

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

BST* insert(BST* root,int k){
    if(root==NULL){
        return createBST(k);
    }
    if(root->key > k){
        root->left = insert(root->left,k);
    }
    else if(root->key <= k){
        root->right = insert(root->right,k);
    }

    return root;
    
}
int maximum(int x,int y){
    if(x>=y)return x;
    else return y;

}
int MaxDeptOfTree(BST *root){
    if(root==NULL){
        return 0;
    }
    int l = MaxDeptOfTree(root->left);
    int r = MaxDeptOfTree(root->right);
    return maximum(l,r)+1;
    
}

int main(){
    

    BST* root = NULL;
    root = insert(root,7);
    root = insert(root,2);
    root = insert(root,1);
    root = insert(root,5);
    root = insert(root,8);
 
    printf("\nInOrder :\n");
    inorder(root);  
    printf("\nMaximum depth of the tree is :");
    printf("\t%d",MaxDeptOfTree(root));
    printf("\n");
}
