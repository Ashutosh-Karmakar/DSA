#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int item;
    struct Node *next;
}node;

void push(node **head,int n){
    node *temp = *head;
    node *new = (node*)malloc(sizeof(node));
    new->item = n;
    new->next = NULL;
    if(temp==NULL){
        *head = new;
    }
    else{
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new;
    }
}
void display(node **head){
    node *root = *head;
    while(root != NULL){
        printf("%d-->",root->item);
        root = root->next;
    }
}

node* findIntersection(node *h1,node *h2){
    node *start1 = h1;
    node *start2 = h2;
    while(1){
        if(h1 == NULL){
            h1 = start1;
        }
        if(h2 == NULL){
            h2 = start2;
        }
        if(h1 == h2){
            return h1;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
}
void insertBeginning(node **root,int x){
    node *node1 = (node *)malloc(sizeof(node));
    if(node1 == NULL){
        printf("There was a problem in creating the node");
    }
    else{
        
        node1->item = x;
        node1->next = *root;
        *root = node1;
    }
}

int main(){
    node *head1 = NULL;
    node *head2 = NULL;
    push(&head1,5);
    push(&head1,10);
    push(&head1,15);
    push(&head1,20);
    push(&head1,30);
    push(&head1,40);
    head2 = head1;
    while(head1->item != 20){
        head1 = head1->next;
    }
    printf("\n%d\n",head2->item);
    insertBeginning(&head1,2);
    insertBeginning(&head1,6);
    
    

    printf("\nThe first list:\n");
    display(&head1);
    printf("\nThe second list:\n");
    display(&head2);

    node *res = findIntersection(head1,head2);  
    printf("\nresult : %d\n",res->item);

}