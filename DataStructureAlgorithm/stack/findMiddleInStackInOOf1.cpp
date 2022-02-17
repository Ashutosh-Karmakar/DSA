#include<iostream>
using namespace std;
class DLLNode{
    public:
    DLLNode *next;
    DLLNode *prev;
    int data;
};
class NewStack{
    public:
    int cnt;
    DLLNode *mid;
    DLLNode *head;
};
NewStack* createStack(){
    NewStack *s = new NewStack();
    s->cnt = 0;
    return s;

}
void push(NewStack *s,int x){
    DLLNode *d1 = new DLLNode();
    d1->data = x;
    d1->prev = NULL;
    d1->next = s->head;
    s->cnt ++;
    if(s->cnt == 1){
        s->mid = d1;
    }
    else{
        s->head->prev = d1;
        if(s->cnt % 2 == 0){
            s->mid = s->mid->prev;
        }
    }
    s->head = d1;
}
int pop(NewStack *s){
    if(s->cnt == 0){
        cout << "The stack is empty" << endl;
        return -1;
    }
    DLLNode *temp = s->head;
    int res;
    s->head = temp->next;
    if(s->head != NULL)
        s->head->prev = NULL;
    s->cnt --;
    // cout << "cnt : " << s->cnt << endl;
    // if(s->cnt == 0){
    //     cout << "datat 0 : " << temp->data << endl;
    //     res = temp->data;
    //     free(temp);
    //     return res;
    // }
    // else if(s->cnt == 1){
    //     s->mid = s->head;
    // }
    // else 
    if(s->cnt%2 != 0){
        s->mid = s->mid->next;
    }
    res = temp->data;
    free(temp);
    return res;
}
int findMiddle(NewStack *s){
    if(s->cnt == 0){
        cout << "The stack is empty" << endl;
        return -1;
    }
    return s->mid->data;
}
int deleteMiddle(NewStack *s){
    if(s->cnt == 0){
        cout<< "The stack is empty" << endl;
        return -1;
    }
    DLLNode *temp = s->mid;
    int res = temp->data;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    else{
        s->head = temp->next;
    }
    s->cnt--;
    if(s->cnt%2 != 0){
        s->mid = s->mid->next;
    }
    else{
        s->mid = s->mid->prev;
    }
    free(temp);
    return res;
}
int main(){
    NewStack *s = createStack();
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);

    cout <<"pop   " << pop(s) << endl;
    cout <<"pop   " <<  pop(s) << endl;
    cout <<"pop   " <<  pop(s) << endl;
    // cout << pop(s) << endl;

    cout << "Middle " <<findMiddle(s) << endl;
    cout << "delete " <<deleteMiddle(s) << endl;
    // cout << s->cnt << endl;

    cout << "Middle " << findMiddle(s) << endl;
    // cout << s->head->data << endl;
    


}