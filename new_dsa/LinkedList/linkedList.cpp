#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *nxt = NULL;
};
void push(Node **head,int data){
    Node *temp = *head;
    Node *newNode = new Node();
    newNode->data = data;
    newNode->nxt = NULL;
    if(temp == NULL){
        *head = newNode;
    }
    else{
        while(temp->nxt != NULL){
            temp = temp->nxt;
        }
        temp->nxt = newNode;
    }
}
void insertAfter(Node **head,int data,int after){
    Node *temp = *head;
    while(temp->data != after){
        temp = temp->nxt;
    }
    Node *temp2 = temp->nxt;
    temp->nxt = new Node();
    temp->nxt->data = data;
    temp = temp->nxt;
    temp->nxt = temp2;
}
void insertEnd(Node **head,int data){
    Node *newNode = new Node();
    newNode->data = data;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while(temp->nxt != NULL){
        temp = temp->nxt;
    }
    temp->nxt = newNode;
    return;
}
void Printl(Node *head){
    while(head!=NULL){
        cout << head->data << " ";
        head = head->nxt;
    }
}

Node * Middle(Node *head){
    Node *fast = head;
    Node *slow = head;
    while(fast!=NULL && fast->nxt != NULL){
        slow = slow->nxt;
        fast = fast->nxt;
        // if(fast!=NULL){
            fast = fast->nxt;
        // }
        
    }
    return slow;
}

Node *Reverse(Node *head){
    Node *prev = NULL;
    Node *temp = head;
    while(head!=NULL){
        head = head->nxt;
        temp->nxt = prev;
        prev = temp;
        temp = head;
    }
    return prev;
}

Node *cur = new Node();
// cur->data = -1;
Node *res = cur;
void rev(Node *head){
    if(head->nxt == NULL){
        cur->nxt = head;
        cur = cur->nxt;
        return;
    }
    Node *temp = head;
    rev(head->nxt);
    cur->nxt = temp;
    cur = cur->nxt;
    cur->nxt = NULL;
}

int main(){
    Node *head = NULL;
    push(&head,10);
    push(&head,20);
    push(&head,30);
    insertAfter(&head,50,20);
    insertEnd(&head,440);
    cout << Middle(head)->data << endl;
    Printl(head);
    cout << endl;
    // Node *prev = Reverse(head);
    rev(head);
    Printl(res->nxt);

}