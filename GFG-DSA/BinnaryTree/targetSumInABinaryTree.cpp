#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;  

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

stack<Node *> s,s2;
Node *insert(Node *root,int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    if(root->data > data){
        root->left = insert(root->left,data);
    }
    else if(root->data < data){
        root->right = insert(root->right,data);
    }
    return root;
}
void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void minStack(struct Node *root){
        if(root==NULL) return;
        struct Node *cur = root;
        while(cur != NULL){
            s.push(cur);
            cur = cur->left;
        }
}
void maxStack(struct Node *root){
        if(root==NULL) return;
        struct Node *cur = root;
        while(cur!= NULL){
            s2.push(cur);
            cur = cur->right;
        }
}
int findMin(){
        if(s.empty()){
            return -1;
        }
        struct Node *temp = s.top();
        s.pop();
        int x = temp->data;
        minStack(temp->right);
        return x;
}
int findMax(){
        if(s.empty()){
            return -1;
        }
        struct Node *temp = s2.top();
        s2.pop();
        int x = temp->data;
        maxStack(temp->left);
        return x;
}

int isPairPresent(struct Node *root, int target)
    {
        if(root == NULL) return 0;
        // inorder(root);
        minStack(root) ;
        maxStack(root) ;
        
        int mi = findMin() ;
        int ma = findMax() ;
        while(mi != ma){
            if(mi+ma > target){
                ma = findMax();
            }
            else if(mi+ma < target){
                mi = findMin();
            }
            else{
                cout << mi << " " << ma << endl; 
                return 1;
            }
        }
        return 0;
        
        
    }

int main(){
    Node *root = NULL;
    root = insert(root,22);
    root = insert(root,18);
    root = insert(root,30);
    root = insert(root,16);
    root = insert(root,20);
    root = insert(root,29);
    root = insert(root,31);


    cout << "\nThe tree inorder is :" << endl;
    inorder(root);
    cout << endl;


    // minStack(root) ;
    // maxStack(root) ;
    // cout << findMin() << " : "<< findMax()<< endl;
    // cout << findMin() << " : "<< findMax()<< endl;
    
    // cout << findMin() << " : "<< findMax()<< endl;
    // cout << findMin() << " : "<< findMax()<< endl;
    cout << "Ans : " << isPairPresent(root,49) << endl;
    // int key = 12;
    // ceilFloorFunc(root,key);
    // cout << "f : "<< f << " | c : " << c << endl;

}