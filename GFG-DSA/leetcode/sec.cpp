#include<iostream>
#include<vector>
using namespace std;
int first = -1;
int last  = -1;
void solve(vector<int> nums,int t,int start,int end){
    if(start > end){
        return;
    }
    int mid = (start + end)/2;
    if(nums[mid] == t){
        if(nums[mid-1] < nums[mid]){
            first = mid;
            solve(nums,t,mid+1,end);
        }
        else{
            solve(nums,t,start,mid-1);
        }
        if(nums[mid+1] > nums[mid]){
            last = mid;
            return;
        }
    }
    else if(nums[mid] > t){
        solve(nums,t,start,mid-1);
    }
    else if(nums[mid] < t){
        solve(nums,t,mid+1,end);
    }
}
int main(){
    vector<int> nums = {5,6,7,7,8,8,8,10,11,12};
    int N = nums.size();
    solve(nums,7,0,N-1);
    cout << first << " :  " << last<< endl;

}
