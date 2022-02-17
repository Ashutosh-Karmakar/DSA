// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// int main(){
//     vector<int> A ={61, -533, -666, -500, 169 ,724 ,478 ,358, -38, -536 ,705 ,-855 ,281 ,-173 ,961 ,-509, -5 
//     ,942, -173,436, -609, -396, 902, -847, -708, -618, 421, -284, 718 ,895 ,447 ,726, -229,
//      538, 869 ,912 ,667 ,-701 ,35 ,894, -297, 811 ,322 ,-667, 673 ,-336, 141 ,711, -747 
//      ,-132 ,547 ,644 ,-338 ,-243 ,-963 ,-141 ,-277 ,741 ,529 ,-222 ,-684, 35 };

//     // vector<int> A = {5,-2,3,1,2};
//     int B = 48;
//     int N = A.size();
//     int f = 0;
//     int l = N-1;
//     int cnt = 0;
//     int sum = 0;
//     int x = 0;
//     while(f <= l && B--){
//         // if(A[f] > A[l]){
//         //     x = A[f];
//         //     sum += A[f];
//         //     f++;
//         // }
//         // else if(A[f] <= A[l]){
//         //     x = A[l];
//         //     sum += A[l];
//         //     l--;
//         // }
//         // cout << x << " ";
//         if(sum + A[f] >= sum + A[l]){
//             x = A[f];
//             sum += A[f];
//             f++;
//         }
//         else{
//             x = A[l];
//             sum += A[l];
//             l--;
//         }
//     }
//     cout << endl;
//     cout << sum << endl;
// }

#include<iostream>
using namespace std;
class Test{
    public:
    Test(){cout << "Constructor";}
};
int main(){
    Test t;
}