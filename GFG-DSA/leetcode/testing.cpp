#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int isPalindrome(string A) {
    transform(A.begin(),A.end(),A.begin(),::tolower);
    cout << A << endl;
    int i = 0;
    int l = A.length()-1;
    cout << (int)A[22] << endl;
    while(i<=A.length()/2){
        cout << (int)A[i] << endl;
        if(A[i] < 48 || (A[i] >57 && A[i] <97) || A[i]>122){
            i++;
        }
        if(A[l] < 48 || (A[l] >57 && A[l] <97) || A[l]>122){
            l--;
        }
        cout << A[i] <<"(" << i <<")" << " " << A[l]<< "(" << l <<")" <<  endl;
        // if(A[i]!=A[l]){
        //     return 0;
        // } 
        i++;
        l--;
    }
    return 1;
}

int main(){
    string A = "A man, a plan, a canal: Panama";
    cout << isPalindrome(A)<<endl;
}