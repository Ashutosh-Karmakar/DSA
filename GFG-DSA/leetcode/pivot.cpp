#include<iostream>
#include<vector>
using namespace std;

int findPivot(int arr[],int left,int right){
    if(left > right){
        return -1;
    }
    if(right == left){
        return right;
    }
    int mid = (left + right)/2;
    if(mid < right && arr[mid] > arr[mid+1]){
        return mid;
    }
    if(mid > left && arr[mid-1] > arr[mid]){
        return mid-1;
    }
    if(arr[left] >= arr[mid]){
        findPivot(arr,left,mid-1);
    }
    return findPivot(arr,mid+1,right);
}

int findPivota(vector<int> A){
    int start = 0;
    int end = A.size()-1;
    while(start <= end){
        if(start == end) return end;
        int mid = (start+end)/2;
        if(mid < end && A[mid] > A[mid+1]){
            return mid;
        }
        if(mid > start && A[mid-1] > A[mid]){
            return mid-1;
        }
        if(A[start] >= A[mid]){
            end = mid-1;
        }
        else if(A[end] <= A[mid]){
            start = mid+1;
        }
    }
    return -1;
}

int finElement(vector<int> A,int B){
    int pivot = findPivota(A);
    int start=0;
    int end=A.size()-1;
    if(B < A[pivot] && B > A[0]){
        start = 0;
        int end = pivot-1;
    }
    if(B < A[pivot] && B < A[0]){
        start = pivot+1;
        end = A.size()-1;
    }
    while(start <= end){
        int mid = (start+end)/2;
        if(A[mid] == B){
            return mid;
        }
        if(A[mid] > B){
            end = mid-1;
        }
        else if(A[mid] < B){
            start = mid + 1;
        }
    }
    return -1;

}
int main(){
    // int arr[] = {40342, 40766, 41307, 42639, 42777, 46079, 47038, 47923, 48064, 48083, 
    // 49760, 49871, 51000, 51035, 53186, 53499, 53895, 59118, 60467, 60498, 60764, 
    // 65158, 65838, 65885, 65919, 66638, 66807, 66989,
    //  67114, 68119, 68146, 68584, 69494, 70914, 72312, 72432, 74536, 77038, 77720, 78590, 78769, 78894, 
    // 80169, 81717, 81760, 82124, 82583, 82620, 82877, 83131, 84932, 85050, 85358, 89896, 90991,
    //  91348, 91376, 92786, 93626, 93688, 94972, 95064, 96240, 96308, 96755, 97197, 97243, 98049, 98407, 98998, 99785,
    //  350, 2563, 3075, 3161, 3519, 4176, 4371, 5885, 6054, 6495, 7218, 7734, 9235, 11899, 13070, 14002, 16258, 
    // 16309, 16461, 17338, 19141, 19526, 21256, 21507, 21945, 22753, 25029, 25524, 27311, 27609,
    //  28217, 30854, 32721, 33184, 34190, 35040, 35753, 36144, 37342};
    // int N = sizeof(arr)/sizeof(arr[0]);

    vector<int> A = {4,5,6,7,8,0,1,2,3};
    int c = finElement(A,5);


    cout <<"Hello " << c;

}