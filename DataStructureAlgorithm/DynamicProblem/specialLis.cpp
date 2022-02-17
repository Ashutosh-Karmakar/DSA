#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> dp(10000,-1);
int slis(vector<int> a,int index,int prev,int d){
    if(index >= a.size()){
        return 0;
    }
    if(prev == -1){
        return max(slis(a,index+1,prev,d),1+slis(a,index+1,index,(a[index+1] - a[index])));
    }
    if((a[index] - a[prev]) > d){
        return slis(a,index+1,prev,d);
    }
    else{
        return max(slis(a,index+1,prev,d),1+slis(a,index+1,index,(a[index+1] - a[index])));
    }

}
int main(){
    // vector<int> a = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    vector<int> a = {1,2,3,4,5};
    cout << slis(a,0,-1,-1) << endl;

}