#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int item;
    struct Node *next;
}node;

void insertBeginning(node **root,int x){
    // printf("hello");
    // int x;
    node *node1 = (node *)malloc(sizeof(node));
    if(node1 == NULL){
        printf("There was a problem in creating the node");
    }
    else{
        // printf("Enter the value want to insert:");
        // scanf("%d",&x);
        node1->item = x;
        node1->next = *root;
        *root = node1;
    }
}

void middle(node **head){
    node *slow = *head;
    node *fast = slow;
    if(slow==NULL){printf("The List is empty");return;}
    while(fast->next!=NULL){
        fast = fast->next;
        if(fast->next){
            fast = fast->next;
        }
        else{
            break;
        }
        slow = slow->next;
    }
    printf("The middle element is : %d \n",slow->item);
}

void display(node **head){
    node *root = *head;
    while(root != NULL){
        printf("%d",root->item);
        if(root->next!=NULL){
            printf("-->");
        }
        root = root->next;
    }
}



int main(){
    node *head = NULL;
    int ch;
    
    insertBeginning(&head,60);
    insertBeginning(&head,50);
    insertBeginning(&head,40);
    insertBeginning(&head,30);
    insertBeginning(&head,20);
    insertBeginning(&head,10);

    display(&head);
    middle(&head);

}