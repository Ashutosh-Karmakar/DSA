#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maxProfit(vector<int> arr,int buy,int index){
    if(index == arr.size()){
        return 0;
    }
    if(buy==-1){
        return max(maxProfit(arr,arr[index],index+1),maxProfit(arr,-1,index+1));
    }
    return max(maxProfit(arr,buy,index+1),arr[index]-buy);

}
int main(){
    vector<int> arr = {2,30,5,85,4,7,100};
    int pro = maxProfit(arr,-1,0);
    cout << pro << endl;
}
