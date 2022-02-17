#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int solveN(vector<int> A,int B,int start,int end){

    int i = 0;
    int f = 0;
    int l = A.size()-1;
    int sum = 0;
    while(i<B && f<A.size() && l>=0){
        i++;
        if(A[l]>A[f]){
            sum = sum + A[l];
            cout << A[l] << "- " << sum << endl;
            l--;
        }
        else if(A[l] <= A[f]){
            sum = sum + A[f];
            cout << A[f] << "- " << sum << endl;
            f++;
        }
        // cout << sum << endl;
        // else if(A[l] == A[f])
    }
    return sum;
}

int main() {
    vector<int> A = {-533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855,
     281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, 
    -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701,
     35, 894, -297, 811, 322, -667, 673, -336,
     141, 711, -747, -132, 547, 644, -338, -243, -963, -141, 
     -277, 741, 529, -222, -684, 35};
    //  sort(A.begin(),A.end());
    int B = 48;
    cout << solveN(A,B,0,A.size()-1) << endl;
}