#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int item;
    struct Node *next;
}node;

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
void display(node **head){
    node *root = *head;
    while(root != NULL){
        printf("%d",root->item);
        if(root->next!=NULL)printf("-->");
        root = root->next;
    }
}
void swap(node **head,node**head2){
    node *temp = *head;
    *head = *head2;
    *head2 = temp;

}
int size(node* temp){
    int cnt=0;
    while(temp!=NULL){
        cnt++;temp=temp->next;
    }
    return cnt;
}
//            large    small   carry
node* add(node *l1,node *l2,int *c){
    if(l1 == NULL || l2 == NULL)return NULL;
    node* result = (node*)malloc(sizeof(node));
    int sum;
    result->next = add(l1->next,l2->next,c);
    sum = l1->item + l2->item + *c;
    *c = sum / 10;
    sum = sum % 10;

    result->item = sum;

    return result;  
}

void addNext(node *l1,node *cur,node **result,int *c){
  
    if(l1!=cur){
        addNext(l1->next,cur,result,c);
        int sum = l1->item + *c;
        sum = sum % 10;
        *c = sum / 10;
        insertBeginning(result,sum);
        printf("%d",sum);
    }
    return;
}


int main(){
    node *head = NULL;  //has to be larger
    node *head2 = NULL; //has to be small

    insertBeginning(&head,3);
    insertBeginning(&head,4);
    insertBeginning(&head,4);

    insertBeginning(&head2,4);
    insertBeginning(&head2,6);
    insertBeginning(&head2,5);
    insertBeginning(&head2,4);
    insertBeginning(&head2,2);
    node *result = NULL;
    int ca = 0;
    if(size(head) == size(head2)){
        result = add(head,head2,&ca);
    }
    else{
        if(size(head) < size(head2)){
            swap(&head,&head2);
        }
        int diff = size(head) - size(head2);
        node *cur = head;
        while(diff--){
            cur = cur->next;
        }
        result = add(cur,head2,&ca);
        addNext(head,cur,&result,&ca);
    }
    if(ca == 1){
        insertBeginning(&result,ca);
    }


    

    
    

    printf("\n\nca:%d\n\n",ca);




    printf("\nlinkedlist 1:\n");
    display(&head);
    printf("\nlinkedlist 2:\n");
    display(&head2);
    printf("\nResult-linked-list:\n");
    display(&result);



}