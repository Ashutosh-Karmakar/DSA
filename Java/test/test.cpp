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
void reverse(node **head){
    node *temp1 = NULL;
    node *temp2 = *head;
    node *temp3;
    while(temp3!=NULL){
        temp3 = temp2->next;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    *head = temp1;
    

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
        printf("\n2.Insert End\n4.Display\n11.Exit\n");
        printf("___________________________________________________________\n");
        printf(":");
        scanf("%d",&ch);
        switch(ch){
            case 2:
                insertBeginning(&head);
                break;
            
            case 4:
                display(&head);
                break;
            
            case 6:
                reverse(&head);
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