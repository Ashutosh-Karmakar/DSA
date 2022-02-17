#include<iostream>
#include<stack>

using namespace std;

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
    cout << root->key << "\t";
    preorder(root->left);
    preorder(root->right);
}
void inorder(BST* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->key << "\t";
    inorder(root->right);
}
void postorder(BST* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->key << "\t";
}

void iterativeInorder(BST *cur){
    // BST *cur = root;
    
    stack<BST*> s;
    s.push(cur);
    cur = cur->left;
    while(true){
        if(cur == NULL && s.empty())break;
        if(cur!=NULL){
            s.push(cur);
            cur = cur->left;
        }
        else{
            cur = s.top();
            s.pop();
            cout << cur->key << "\t" ;
            cur = cur->right;
        }
    }
}
void iterativePreorder(BST *cur){
    // BST *cur = root;
    
    stack<BST*> s;
    s.push(cur);
    cout << cur->key << "\t" ;
    cur = cur->left;
    while(true){
        if(cur == NULL && s.empty())break;
        if(cur!=NULL){
            cout << cur->key << "\t" ;
            s.push(cur);
            cur = cur->left;
        }
        else{
            cur = s.top();
            s.pop();
            cur = cur->right;
        }
    }
}
void iterativePostorder(BST *cur){
    // BST *cur = root;
    
    stack<BST*> s1;
    stack<BST*> s2;
    s1.push(cur);
    BST *temp;
    while(!s1.empty()){
        temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left != NULL){
            s1.push(temp->left);
        }
        if(temp->right != NULL){
            s1.push(temp->right);
        }
    }
    while(!s2.empty()){
        cout << s2.top()->key << "\t";
        s2.pop();
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
    
    cout << "\nInOrder-recursive :\n";
    inorder(root);  
    
    cout << "\nInOrder-iterative :\n";
    iterativeInorder(root);   

    cout << "\nPreOrder-recursive :\n";
    preorder(root); 

    cout << "\nPreOrder-iterative :\n";
    iterativePreorder(root); 

    cout << "\nPostOrder-recursive :\n";
    postorder(root);

    cout << "\nPostOrder-iterative :\n";
    iterativePostorder(root);
}
