#include<iostream>
using namespace std;
// class Student {
//     public:
//     int id;
//     string name;

//     void print(){
//         cout << id << "\n" << name << endl;
//     }

// };
// // int add(double a){
// //     return a+2;
// // }
// // int add(int a){
// //     return a;
// // }
// int main(){
//     // int a = 20;
//     // double d = 20.0;
//     // cout << add(a) << endl;
//     // cout << add(d) << endl;

//     Student s1;
//     s1.id = 2;
//     s1.name = "ashu";
//     s1.print();
// }

class A{
    public:
    int x = 20;
};
class B : public A{
    public:
    void print(){
        cout << x << endl;
    }
};
int main(){
    B b1;
    b1.print();
}