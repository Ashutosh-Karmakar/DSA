#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct BST{
    int key;
    struct BST *left,*right;
}BST;
int f = -1;
int r = -1;

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
    else if(root->key < k){
        root->right = insert(root->right,k);
    }

    return root;
    
}

int isEqual(BST *root1,BST *root2){
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;
    if(root1->key!=root2->key)
        return 0;
    return isEqual(root1->left,root2->left) && isEqual(root1->right,root2->right);
}

int main(){
    

    BST* root1 = NULL;
    root1 = insert(root1,7);
    root1 = insert(root1,5);
    root1 = insert(root1,8);
    root1 = insert(root1,4);
    root1 = insert(root1,6);
    root1 = insert(root1,9);


    BST* root2 = NULL;
    root2 = insert(root2,7);
    root2 = insert(root2,5);
    root2 = insert(root2,8);
    root2 = insert(root2,4);
    root2 = insert(root2,6);
    root2 = insert(root2,9);





 
    printf("\nInOrder :\n");
    inorder(root1); 
    
    printf("\nInOrder :\n");
    inorder(root2);  
    printf("\nThe list is same(1) or not(0) : %d\n",isEqual(root1,root2));
    
    printf("\n");
}
