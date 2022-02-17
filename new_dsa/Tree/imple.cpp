#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Node{
    int data;
    struct Node *l;
    struct Node *r;
    Node(int da){
        data = da;
        l = NULL;
        r = NULL;
    }
};

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->l);
    cout << root->data << " ";
    inorder(root->r);
}

void postorder(Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->l);
    postorder(root->r);
    cout << root->data << " ";
}

void preorder(Node *root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->l);
    preorder(root->r);
}

int height(Node *root){
    if(root == NULL){
        return -1;
    }
    return max(height(root->l),height(root->r))+1;
}

void traversal(Node *root,int level){
    if(root == NULL){
        return;
    }
    if(level == 0){
        cout << root->data << " ";
    }
    if(level > 0){
        traversal(root->l,level-1);
        traversal(root->r,level-1);
    }
}

void levelRecur(Node *root){
    int h = height(root);
    for(int i=0;i<=h;i++){
        traversal(root,i);
    }
}

void LevelQue(Node *root){
    queue<Node *> que;
    Node *temp;
    que.push(root);
    while(!que.empty()){
        int s = que.size();
        while(s--){
            temp = que.front();
            cout << temp->data << " ";
            que.pop();
            if(temp->l != NULL){
                que.push(temp->l);
            }
            if(temp->r != NULL){
                que.push(temp->r);
            }
        }
        cout << endl;
    }

}

int maxi = 0;
int diam(Node *root){
    if(root == NULL){
        return 0;
    }
    int L = diam(root->l);
    int R = diam(root->r);
    maxi = max(maxi,L+R+1);
    return max(L,R)+1;
}
int diameter(Node *root){
    maxi = 0;
    diam(root);
    return maxi;
}

bool ancestor(Node *root,int d){
    if(root == NULL){
        return false;
    }
    if(root->data == d){
        return true;
    }
    if(ancestor(root->l,d) || ancestor(root->r,d)){
        cout << root->data << " ";
        return true;
    }
    return false;
}

int main(){

    Node *root = new Node(8);
    root->l = new Node(7);
    root->r = new Node(6);
    root->l->l = new Node(10);
    root->l->r = new Node(11);
    root->r->l = new Node(12);
    root->r->l->l = new Node(14);
    root->r->l->l->r = new Node(14);
    cout << "PreOrder" << endl;
    preorder(root);
    cout << endl;
    cout << "Inorder" << endl;
    inorder(root);
    cout << endl;
    cout << "PostOrder" << endl;
    postorder(root);
    cout << endl;
    cout << "Height Of The Tree : " << height(root) << endl;

    cout << "Level Order Traversal: " << endl;
    levelRecur(root);
    cout << endl;
    LevelQue(root);

    cout << "\nDiameter: "<< diameter(root) << endl;

    cout << "\nAncestor of " << 14 << " are :" << endl;
    ancestor(root,14);

}