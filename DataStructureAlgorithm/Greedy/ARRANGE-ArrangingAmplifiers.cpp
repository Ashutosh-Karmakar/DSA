#include<iostream>
#include<algorithm>
using namespace std;
void function(int arr[],int n){
    sort(arr,arr+n,greater<int>());
   
    int i;
    int cnt = 0;
    for(i=n-1;i>=0;i--){
        if(arr[i] != 1){
            break;
        }
        cnt++;
    }
    cout << cnt << endl;
    if(i!=n-1){
        for(int j=n-1;j>0;j--){
            arr[j] = arr[j-cnt];
        }
        int k = 0;
        while(cnt--){
            arr[k] = 1;
            k++;
        }
    }
    if(arr[n-1] == 2 && arr[n-2] == 3){
        int temp = arr[n-1];
        arr[n-1] = arr[n-2];
        arr[n-2] = temp;
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        int arr[100];
        for(int i=0;i<x;i++){
            cin >> arr[i];
        }
        function(arr,x);
    }
}