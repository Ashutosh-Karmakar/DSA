#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> A){
    int start = 0;
    int end = A.size();
    int index = -1;
    while(start <= end){
        int mid = (start+end)/2;
        int next = mid+1;
        int prev = mid-1;
        if(next >= A.size()){
            next = mid;
        }
        if(prev < 0){
            prev = mid;
        }
        if(A[mid] >= A[next] && A[mid] >= A[prev]){
            index = mid;
            break;
        }
        if(A[prev] > A[mid]){
            end = mid-1;
        }
        else if(A[next] > A[mid]){
            start = mid+1;
        }
    }
    // cout <<"HELLO " << index << endl;
    return index;
}
int findElement(vector<int> A,int B,int start,int end){
        while(start <= end){
        int mid = (start + end)/2;
        if(A[mid] == B){
            return mid;
        }
        if(A[mid] < B){
            start = mid +1;
        }
        else if(A[mid] > B){
            end = mid -1;
        }
    }
    return -1;
}
int solve(vector<int> &A, int B) {
    int index = findPivot(A);
    if(index == -1)
        return 0;
    if(A[index] == B){
        return index;
    }
    for(int i=index+1;i<A.size();i++){
        cout << A[i] << " ";
    }
    cout << endl;
    
    for(int i=0;i<index;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    int x1 = findElement(A,B,index+1,A.size());
    cout << "hel " <<x1 << endl;
    if(x1 == -1){
        cout << " Inde" << endl;
        x1 = findElement(A,B,0,index);
    }
    cout << "hel " <<x1 << endl;
    return x1;
    
}

int main(){
    vector<int> A = {  1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    int B = 5;
    int c = findPivot(A);
    cout << solve(A,B) << endl;;

    cout <<"HELLO " << c << " " << A[c] << endl;
}