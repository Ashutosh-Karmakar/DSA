#include<stdio.h>
#include<stdlib.h>
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
void preorder(BST* root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->key);
    preorder(root->left);
    preorder(root->right);
}
void inorder(BST* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->key);
    inorder(root->right);
}
void postorder(BST* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->key);
}

int search(BST* root,int k){
    if(root == NULL){
        return -1;
    }
    if(root->key == k){
        return root->key;
    }
    if(root->key > k){
        return search(root->left,k);
    }
    else if(root->key < k){
        return search(root->right,k);
    }

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
BST* inorderSuccesor(BST* node){
    BST* curr = node;
    if(curr != NULL && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
BST* delete(BST* root,int k){
    if(root == NULL){//return if tree is empty
        return root;
    }
    //find the node area >>>
    if(k > root->key){
        root->right = delete(root->right,k);
    }
    else if(k < root->key){
        root->left = delete(root->left,k);
    }
    else{
        if(root->left == NULL){
            BST *temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            BST *temp = root->left;
            free(root);
            return temp;
        }
        else{
            BST* temp = inorderSuccesor(root->right);
            root->key = temp->key;
            root->right = delete(root->right,temp->key);
        }
    }
    return root;
}

int main(){
    

    BST* root = NULL;
    root = insert(root,8);
    root = insert(root,3);
    root = insert(root,10);
    root = insert(root,1);
    root = insert(root,6);
    root = insert(root,11);
    root = insert(root,7);
    root = insert(root,4);
    printf("\nThe Result is : %d\n",search(root,9));
    printf("\nPreOrder :\n");
    preorder(root);  
    root = delete(root,3);




    printf("\nPreOrder :\n");
    preorder(root);  
    printf("\nInOrder :\n");
    inorder(root);  
    printf("\nPostOrder :\n");
    postorder(root);  
}
