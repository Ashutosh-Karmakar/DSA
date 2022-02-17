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


void merge(node **h1,node **h2){
    // node **result = h1;
    node *l1 = *h1;
    node *l2 = *h2;
    node *temp = NULL;
    while(1){
        if(l1==NULL){
            temp->next = l2;
            break;
        }
        if(l2==NULL){
            temp->next = l1;
            break;
        }
        if(l1->item <= l2->item){
            temp = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            node *t = l1;
            l1 = l2;
            l2 = t;
        }
    }
    // display(result);
   

}

int main(){
    node *head1 = NULL;
    node *head2 = NULL;
    push(&head1,5);
    push(&head1,10);
    push(&head1,15);
    

    push(&head2,2);
    push(&head2,6);
    push(&head2,20);
    merge(&head2,&head1);

    printf("\nThe first list:\n");
    display(&head1);
    printf("\nThe second list:\n");
    display(&head2);

}