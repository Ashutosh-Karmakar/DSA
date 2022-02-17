#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int item;
    struct Node *next;
}node;

void insertBeginning(node **root){
    int x;
    node *temp = *root;
    node *head = *root;
    node *node1 = (node *)malloc(sizeof(node));
    if(node1 == NULL){
        printf("There was a problem in creating the node");
    }
    else{
        printf("Enter the value want to insert:");
        scanf("%d",&x);
        node1->item = x;
        node1->next = *root;
        *root = node1;
        head = *root;
        if(temp == NULL){
            head->next = node1;
            return;
        }
        while(head!=temp){
            head = head->next;
        }
        head->next = *root;
    }
}
void insertEnd(node **head){
    int x;
    node *temp = *head;
    node *root = *head;
    node *node1 = (node *)malloc(sizeof(node));
    if(node1 == NULL){
        printf("There is some problem in creation of the node");
    }
    else{
        printf("Enter the value want to insert:");
        scanf("%d",&x);
        node1->item = x;
        node1->next = temp;
        if(root == NULL){
            root = node1; 
        }
        else{
            while(root->next != *head){
                root = root->next; 
            }
            root->next = node1;
        }
    }
}
void insertBetween(node **head){
    int x;
    int n;
    node *root = *head;
    node *temp;
    node *node1 = (node *)malloc(sizeof(node));
    if(node1 == NULL){
        printf("There is some problem in creation of the node");
    }
    else{
        printf("Enter the value want to insert:");
        scanf("%d",&x);
        printf("Enter the number after which you want to insert:");
        scanf("%d",&n);
        node1->item = x;
        node1->next = NULL;
        while(root->item != n){
            root = root->next;
        }
        temp = root->next;
        root->next = node1;
        node1->next = temp;
        
    }
}
void display(node **head){
    node *root = *head;
    node *temp = *head;
    printf("%d-->",root->item);
    root = root->next; 
    while(root->item != temp->item){
        printf("%d-->",root->item);
        root = root->next;
    }
}



int main(){
    node *head = NULL;
    int ch;
    while(1){
        printf("\n___________________________________________________________");
        printf("\n1.Insert Beginning\n2.Insert End\n3.Insert Between\n4.Display\n5.Exit\n");
        printf("___________________________________________________________\n");
        printf(":");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insertBeginning(&head);
                break;
            case 2:
                insertEnd(&head);
                break;
            case 3:
                insertBetween(&head);
                break;
            case 4:
                display(&head);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Wrong entry");
                break;
        }
        
    }

}