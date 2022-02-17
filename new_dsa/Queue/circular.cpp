#include<iostream>
using namespace std;

#define maxi 4
int f = -1;
int r = -1;
int *que = new int[maxi];

void enQue(int x){
    if((f == -1 && r == maxi-1 )|| (r == (f-1)%maxi))
    {
        cout << "Queue is Full" << endl;
        return ;
    }
    if(f == -1) f++;
    r=(r+1)%maxi;
    que[r] = x;
}

int deQue(){
    if(f==-1 ){
        cout << "Queue is Empty" << endl;
        return -1;
    }
    
    int x = que[f];

    if(f==r){
        f = -1;
        r = -1;
    }
    f = (f+1)%maxi;
    return x;
}
int main(){
    enQue(1);
    enQue(2);
    enQue(3);
    enQue(4);

    cout << deQue() << endl;
    cout << deQue() << endl;
    enQue(1);
    enQue(1);
    
    cout << deQue() << endl;
    cout << deQue() << endl;
    
    cout << deQue() << endl;
    cout << deQue() << endl;
}