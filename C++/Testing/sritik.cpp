#include<iostream>
using namespace std;
struct Node{
    int x;
    int y;
    Node(){
        x = 2;
        y = 3;
    }
};
int main(){
    Node *n = new Node();
    cout << n->x <<" " << n->y << endl;
}