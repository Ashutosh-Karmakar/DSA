#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int item;
    struct Node *next;
}node;

void insertBeginning(node **root){
    printf("hello");
    int x;
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
    }
}
void insertEnd(node **head){
    int x;
    node *root = *head;
    node *node1 = (node *)malloc(sizeof(node));
    if(node1 == NULL){
        printf("There is some problem in creation of the node");
    }
    else{
        printf("Enter the value want to insert:");
        scanf("%d",&x);
        node1->item = x;
        node1->next = NULL;
        if(root == NULL){
            root = node1; 
        }
        else{
            while(root->next != NULL){
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
void deleteBegin(node **head){
    if(*head == NULL){
        printf("The Linked List is empty");
        return;
    }
    node *temp = *head;
    *head = temp->next;
    free(temp);
}
void deleteEnd(node **head){
    if(*head == NULL){
        printf("The Linked List is empty");
        return;
    }
    node *temp = *head;
    node *temp2 = NULL;
    while(temp->next != NULL){
        temp2 = temp;
        temp = temp->next;
    }
    if(temp2 == NULL){
        printf("hello");
        free(temp);
        *head = NULL;
        return;
    }
    temp2->next = NULL;
    free(temp);
    
}
void display(node **head){
    node *root = *head;
    while(root != NULL){
        printf("%d-->",root->item);
        root = root->next;
    }
}



int main(){
    node *head = NULL;
    int ch;
    while(1){
        printf("\n___________________________________________________________");
        printf("\n1.Insert Beginning\n2.Insert End\n3.Insert Between\n4.Display\n5.Delete Begin\n6.Delete Begin\n11.Exit\n");
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
                deleteBegin(&head);
                break;
            case 6:
                deleteEnd(&head);
                break;
             case 11:
                exit(0);
                break;
            default:
                printf("Wrong entry");
                break;
        }
        
    }

}