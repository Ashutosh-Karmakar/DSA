#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *l;
    Node *r;
    Node(int d){
        data = d;
        l = NULL;
        r = NULL;
    }
};
Node *insert(Node *root,int data){
    if(root == NULL){
        return new Node(data);
    }
    else if(root->data < data){
        root->r = insert(root->r,data);
    }
    else{
        root->l = insert(root->l,data);
    }
    return root;
}
void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->l);
    cout << root->data << " ";
    inorder(root->r);
}

Node *search(Node *root,int key){
    if(root == NULL){
        return NULL;
    }
    else if(root->data == key){
        return root;
    }
    else if(root->data < key){
        return search(root->r,key);
    }
    return search(root->l,key);
}

Node *succesor(Node *root){
    while(root!= NULL || root->l != NULL){
        root = root->l;
    }
    return root;
}

Node * deleteNode(Node *root,int key){
    if(root == NULL){
        return root;
    }
    else if(root->data > key){
        root->l = deleteNode(root->l,key);
    }
    else if(root->data < key){
        root->r = deleteNode(root->r,key);
    }
    else{
        if(root->l == NULL && root->r == NULL){
            return NULL;
        }
        else if(root->l == NULL){
            Node *temp = root->r;
            free(root);
            return temp;
        }
        else if(root->r == NULL){
            Node *temp = root->l;
            free(root);
            return temp;
        }
        else{
            Node *succ = succesor(root->r);
            root->data = succ->data;
            root->r = deleteNode(root->r,succ->data);
        }
    }
    return root;
}
int main(){
    Node *root = NULL;
    root = insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    inorder(root);

    if(search(root,50)== NULL){
        cout << "\nElement Not Found" << endl;
    }
    else{
        cout << "\nelement is found" << endl;
    }
    cout << "After Deletion : " << endl;
    root = deleteNode(root,40);
    inorder(root);
}