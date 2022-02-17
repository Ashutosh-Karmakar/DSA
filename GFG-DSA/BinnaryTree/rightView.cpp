#include<iostream>
#include<queue>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node *l,*r;
};
Node* newNode(int d){
    Node *new1 = new Node();
    new1->data = d;
    new1->l = NULL;
    new1->r = NULL;
    return new1;
}

int height(Node *root){
    if(root==NULL){
        return -1;
    }
    return max(height(root->l),height(root->r))+1;
}



void traversal(Node *root,int level){
    if(root==NULL){
        return;
    }
    else if(level == 0){
        cout << root->data << "\t";
    }
    else if(level > 0){
         
        traversal(root->l,level-1);
        traversal(root->r,level-1);

    }
}
void levelOrderTreaversalAlsoKnownAsBFS(Node *root){
    int h = height(root);
    for(int i=0;i<=h;i++){
        traversal(root,i);
        cout << endl ; 
    }
}

void levelOrderTraversalUsingQue(Node *root){
    queue<Node *> q;
    map<int,int> m;
    q.push(root);
    int size;
    Node *temp;
    int l = 0;
    while(!q.empty()){
        size = q.size();
        for(int i=0;i<size;i++){
            temp = q.front();
            m[l] = temp->data;
            q.pop();
            // cout << temp->data << "\t";
            if(temp->l != NULL){
                q.push(temp->l);
            }
            if(temp->r != NULL){
                q.push(temp->r);
            }
        }
        l++;
    }
    for(int i=0;i<m.size();i++){
        cout << m[i] << "\t";
    }
    cout << endl;

}

int main(){
    Node *root = newNode(8);
    root->l = newNode(7);
    root->r = newNode(6);
    root->l->l = newNode(10);
    root->l->r = newNode(11);
    root->r->l = newNode(12);
    root->r->l->l = newNode(14);
    // root->r->l->l->r = newNode(14);

    cout << "The height of the tree is :" << endl;
    cout << height(root) << endl;
    
    cout << "The level Order traversal is : - recursive" << endl;
    levelOrderTreaversalAlsoKnownAsBFS(root);
    cout << endl;

    cout << "The level Order traversal is : - queue" << endl;
    levelOrderTraversalUsingQue(root);
    cout << endl;
}