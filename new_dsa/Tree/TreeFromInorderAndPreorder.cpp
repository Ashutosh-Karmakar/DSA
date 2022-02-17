#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node *l;
    Node *r;
    Node(int d){
        data = d;
        l = NULL;
        r = NULL;
    }
};
int id = 0;
Node *transform(int preorder[],int start,int end,map<int,int> m){
    if(end < start){
        return NULL;
    }
    Node *root = new Node(preorder[id++]);
    if(start == end){
        return root;
    }
    int pos = m[root->data];
    root->l = transform(preorder,start,pos-1,m);
    root->r = transform(preorder,pos+1,end,m);
    return root;
}

Node *solve(int preorder[],int inorder[],int n){
    map<int,int> m;
    m.clear();
    for(int i=0;i<n;i++){
        m[inorder[i]] = i;
    }
    return transform(preorder,0,n-1,m);
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
void inorderTrav(Node *root){
    if(root==NULL){
        return;
    }
    inorderTrav(root->l);
    cout << root->data << "\t";
    inorderTrav(root->r);
}
void rightView(Node *root){
    queue<Node *> que;
    map<int,int> m;
    que.push(root);
    Node *temp;
    int i=0;
    while(!que.empty()){
        int s = que.size();
        while(s--){
            temp = que.front();
            m[i] = temp->data;
            que.pop();
            if(temp->l != NULL){
                que.push(temp->l);
            }
            if(temp->r != NULL){
                que.push(temp->r);
            }
        }
        i++;
    }
    for(int i=0;i<m.size();i++){
        cout << m[i] << endl;
    }
}

void leftView(Node *root){
    queue<Node *> que;
    map<int,int> m;
    que.push(root);
    Node *temp;
    int i=0;
    while(!que.empty()){
        int s = que.size();
        while(s--){
            temp = que.front();
            // cout << i << endl;
            if(m.count(i) == 0){
                m[i] = temp->data;
            }
            que.pop();
            if(temp->l != NULL){
                que.push(temp->l);
            }
            if(temp->r != NULL){
                que.push(temp->r);
            }
        }
        i++;
    }
    for(int i=0;i<m.size();i++){
        cout << m[i] << endl;
    }
}
map<int,int> map1;
void topView(Node *root,int d){
    if(root == NULL){
        return;
    }
    if(map1.count(d) == 0 )
        map1[d] = root->data;
    topView(root->l,d-1);
    topView(root->r,d+1);
}
map<int,int> map2;
void bottomView(Node *root,int d){
    if(root == NULL){
        return;
    }
    
    map2[d] = root->data;
    // cout     << root->data;
    bottomView(root->l,d-1);
    bottomView(root->r,d+1);
}
int main(){
    int inorder[] = {4,2,5,1,6,3};
    int preOrder[] ={1,2,4,5,3,6};
    Node *root = NULL;
    int N = 6;
    root = solve(preOrder,inorder,N);
    LevelQue(root);
    cout << endl;
    inorderTrav(root);
    cout << "\nRight View: " <<endl;
    rightView(root);
    cout << "\nLeft View: " << endl;
    leftView(root);
    topView(root,0);
    cout << "\nTop View:" << endl;
    for(auto it=map1.begin();it!=map1.end();it++){
        cout << it->second << endl;
    }
    cout << endl;
    bottomView(root,0);
    cout << "\nBottom View:" << endl;
    for(auto it=map2.begin();it!=map2.end();it++){
        cout << it->second << endl;
    }



}
