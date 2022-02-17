#include<iostream>
#include<unordered_map>

using namespace std;

class Node {
    public :
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

unordered_map<int,int> m;
int i =0;
Node *create(int inor[],int preo[],int start,int end){
    if(start > end){
        return NULL;
    }
    
    Node *node = new Node(preo[i++]);
    cout << "Hello: "<< node->data << endl;
    if(start == end) return node;
    int pos = m[node->data];
    

    node -> left = create(inor,preo,start,pos-1);
    node -> right = create(inor,preo,pos+1,end);
    return node;
    

}

void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    int inor[] = {2,1,3};
    int preo[] = {1,2,3};
    m.clear();
    for(int i=0;i<3;i++){
        cout << "m: "<< inor[i] << " -- i: " << i << endl;

        m[inor[i]] = i;
    }
    for(auto i:m){
        cout << i.first << " : " << i.second << endl;
    }


    Node *root = create(inor,preo,0,2);

    cout << "The inorder is :" << endl;
    inorder(root);
    cout << endl;


}