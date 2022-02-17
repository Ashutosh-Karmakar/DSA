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

void LeftView(BST *root){
    push(root);
    int sz;
    while(f<r+1){
        sz = queSize();
        for(int i=0;i<sz;i++){
            BST* cur = pop();
            if(i==0){
                printf("%d\t",cur->key);
            }
            if(cur->left != NULL){
            push(cur->left);
            }
            if(cur->right != NULL){
                push(cur->right);
            }
        }     
    }
}
void RightView(BST *root){
    push(root);
    int sz;
    while(f<r+1){
        sz = queSize();
        for(int i=0;i<sz;i++){
            BST* cur = pop();
            if(i==sz-1){
                printf("%d\t",cur->key);
            }
            if(cur->left != NULL){
            push(cur->left);
            }
            if(cur->right != NULL){
                push(cur->right);
            }
        }     
    }
}

int main(){
    

    BST* root = NULL;
    root = insert(root,7);
    root = insert(root,5);
    root = insert(root,8);
    root = insert(root,4);
    root = insert(root,6);
    root = insert(root,9);





 
    printf("\nInOrder :\n");
    inorder(root);  
    printf("\nLeftView :\n");
    LeftView(root);
      
    printf("\nRightView :\n");
    RightView(root);
    printf("\n");
}
