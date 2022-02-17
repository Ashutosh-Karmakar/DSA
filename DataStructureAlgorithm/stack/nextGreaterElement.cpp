#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int arr[] = { 1, 3, 2, 4 };
    int N = 4;
    vector<int> ans;
    stack<int> s;
    if(N==0){
        ans.push_back(-1);
    }
    for(int i=N-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(s.top() < arr[i]){
            while(!s.empty()){
                if(s.top() > arr[i]){
                    break;
                }
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
            
        }
        else{
            ans.push_back(s.top());
        }
        s.push(arr[i]);
    }

    cout << "The ans is : " << endl;
    for(int i=N-1;i>=0;i--){
        cout << ans[i] << " " ;
    }
    cout << endl;
}
