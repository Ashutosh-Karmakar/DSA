#include<iostream>
using namespace std;
class DLL{
    public:
    int data;
    DLL *prev;
    DLL *next;
    DLL(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};


void push(DLL **root,int data){
    DLL *newNode = new DLL(data);
    newNode->next = (*root);
    newNode->prev = NULL;
    if((*root)!=NULL){
        (*root)->prev = newNode;
    }
    *root = newNode;
}

void printDLL(DLL *root){
    DLL*temp;
    while(root!=NULL){
        temp = root;
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
     while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
DLL * findMid(DLL *root,int mid){
    int i=0;
    while(i<mid){
        i++;
        root = root->next;
    }
    return root;
}

DLL *ende;
DLL *first;
DLL * DLLtoBinTree(DLL *root,int start,int end){

    if(start > end){
        return NULL;
    }
    int mid = (start+end)/2;
    DLL *temp = findMid(root,mid);
    cout << temp->data << endl;
    if(start == end){
        if(temp->prev == NULL){
            first = NULL;
        }
        if(temp->next == NULL){
            ende = temp;
        }
        return temp;
    }
    temp->prev = DLLtoBinTree(root,start,mid-1);
    temp->next = DLLtoBinTree(root,mid+1,end);
    return temp;
}


void inorder(DLL *root){
    if(root == NULL){return;}
    inorder(root->prev);
    cout << root->data << " ";
    inorder(root->next);
}
int main(){

    DLL *root = NULL;
    push(&root,7);
    push(&root,6);
    push(&root,5);
    push(&root,4);
    push(&root,3);
    push(&root,2);
    push(&root,1);
    
    cout << "The DLL is as follows:" << endl;
    printDLL(root);

    int len = 6;
    DLL *ans = DLLtoBinTree(root,0,len);
cout << "The : " << ans->data << endl;
cout << "The : " << ans->prev->next->prev->data << endl;
    if(ans == NULL){
        cout << "sorry didnt work" << endl;
    }

    ende->prev = NULL;
    first->next = NULL;

    cout << "The inorder traversal is : " << endl;
    inorder(ans);

}




// struct Comparator{
// 	bool operator() (Movie *a,Movie *b){
// 		return a.releaseDate > b.releaseDate;	
// 	}
// };

// DLL *floyd(DLL *head){
//     DLL *slow = head;
//     DLL *fast = head->next;
//     while(fast && fast->next){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     return slow;
// }
// DLL * DLLtoBinTree(DLL *root){ 
//     if(root==NULL){
//         return NULL;
//     }
//     DLL *mid= floyd(root);
//     if(mid == root){
//         mid->prev=NULL;
//         mid->next=NULL;
//         return mid;
//     }
//     mid->prev->next=NULL;
//     mid->prev= DLLtoBinTree(root);
//     mid->next= DLLtoBinTree(mid->next);
//     return mid;
// }
