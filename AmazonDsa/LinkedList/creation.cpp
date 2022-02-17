#include<iostream>
using namespace std;
struct Node {
    int data;
    Node *nxt;
    Node(int d){
        data = d;
        nxt = NULL;
    }
};
Node* insertEnd(Node **head,int data){
    Node *temp = *head;
    Node *newNode = new Node(data);
    if(temp == NULL){
        return newNode;
    }
    while(temp->nxt != NULL){
        temp = temp->nxt;
    }
    temp->nxt = newNode;
    return *head;
}
Node* insertBegin(Node **head,int data){
    
    Node *newNode = new Node(data);
    newNode->nxt = *head;
    *head = newNode;
    return *head;
}
void deleteEnd(Node **head){
    Node *temp = *head;
    if(temp == NULL){
        cout << "No Element present in the linked list" << endl;
        return;
    }
    while(temp->nxt->nxt != NULL){
        temp = temp->nxt;
    }
    Node *temp2 = temp->nxt;
    temp->nxt = NULL;
    free(temp2);
}
void deleteBegin(Node **head){
    Node *temp = *head;
    Node *temp2 = temp;
    *head = temp->nxt;
    free(temp2);
}
void swap(Node **head,int d1,int d2){
    Node *curX = *head;
    Node *curY = *head;
    Node *prevX = *head;
    Node *prevY = *head;
    Node *temp = *head;
    Node *prev = *head;
    while(temp != NULL){       
        if(d1 == temp->data){
            curX = temp;
            prevX = prev;
        }
        if(d2 == temp->data){
            curY = temp;
            prevY = prev;
        }
        prev = temp;
        temp = temp->nxt;
    }
    if(prevX != NULL){
        prevX->nxt = curY;
    }
    else{
        *head = curY;
    }
    if(prevY != NULL){
        prevY->nxt = curX;
    }
    else{
        *head = curY;
    }
    Node *temp2 = curX->nxt;
    curX->nxt = curY->nxt;
    curY->nxt = temp2;
}
void printNodes(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->nxt;
    }
}
int main(){
    Node *head = NULL;
    head = insertEnd(&head,10);
    insertEnd(&head,20);

    insertEnd(&head,30);
    insertBegin(&head,40);
    insertEnd(&head,80);
    // deleteEnd(&head);
    // deleteBegin(&head);
    printNodes(head);
    cout << endl;
    // deleteBegin(&head);
    swap(&head,10,20);
    printNodes(head);
}