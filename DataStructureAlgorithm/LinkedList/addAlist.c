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
void reverse(node **root){
    node *temp1 = NULL;
    node *temp2 = *root;
    node *temp3 = temp2;
    while(temp3!=NULL){
        temp3 = temp2->next;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    *root = temp1;
    node *t = *root;
    

}


void display(node **head){
    node *root = *head;
    while(root != NULL){
        printf("%d-->",root->item);
        root = root->next;
    }
}


void add(node **h1,node **h2){
    node *r1 = *h1;
    node *r2 = *h2;
    int c = 0;
    int sum = 0;
    node *result = NULL;
    while(1){
        if(r1 == NULL){
            while(r2!=NULL){
                sum = r2->item+c;
                push(&result,sum%10);
                c = sum / 10;
                r2 = r2->next;
            }
            break;
        }
        if(r2 == NULL){
            while(r1!=NULL){
                sum = r1->item;
                printf("%d",sum);
                push(&result,sum%10 + c);
                c = sum / 10;
                r1 = r1->next;
            }
            break;
        }
        sum = r1->item + r2->item + c;
        push(&result,sum%10);
        c = sum/10;
        r1 = r1->next;
        r2 = r2->next;
    }
    reverse(&result);
    display(&result);
        
}



int main(){
    node *head1 = NULL;
    node *head2 = NULL;
    push(&head1,8);
    push(&head1,6);
    push(&head1,1);

    push(&head2,8);
    push(&head2,9);
    push(&head2,1);
    push(&head2,4);
    push(&head2,3);
    

   
    printf("\n1st:\n");
    display(&head1);
    printf("\n2nd:\n");
    display(&head2);
    printf("\nadding:\n");
    reverse(&head1);
    reverse(&head2);
    add(&head1,&head2);
    
    
}