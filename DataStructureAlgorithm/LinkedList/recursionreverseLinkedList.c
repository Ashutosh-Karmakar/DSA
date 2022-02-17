#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
void push(node **head,int x){
    node* root = *head;
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        printf("The node is null {ERROR}");
        exit(0);
    }
    newNode->data = x;
    newNode->next = NULL;
    if(root == NULL){
        
        *head = newNode;
        
        return;
    }
    while(root->next){
        root = root->next;
    }
    root->next = newNode;
}
void display(node *head){
    while(head){
        printf("%d",head->data);
        if(head->next != NULL){
            printf("--> ");
        }
        head = head->next;
    }
}

void reverse(node **head,node *cur){
    if(cur->next == NULL){
        *head = cur;
        return;
    }
    reverse(&*head,cur->next);
    node *temp = cur->next;
    temp->next = cur;
    cur->next = NULL;
}

int main(){
    node *head = NULL;

    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);

    printf("The Linked List is :\n");
    display(head);
    printf("\n");

    reverse(&head,head);
    printf("The Reverse Linked List is :\n");
    display(head);
    printf("\n");
    

}