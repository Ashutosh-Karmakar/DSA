#include<iostream>
#include<vector>

using namespace std;

int main(){
    int sumMax = 10;
    vector<int> a = {4,2,4,6,1};
    vector<int> b = {2,1,8,5};
    vector<int> suma(a.size());
    suma[0] = a[0];
    vector<int> sumb(b.size());
    sumb[0] = b[0];
    for(int i=1;i<a.size();i++){
        suma[i] = a[i] + suma[i-1];
    }
    for(int i=1;i<b.size();i++){
        sumb[i] = b[i] + sumb[i-1];
    }
    for(int i:suma){
        cout << i << " ";
    }
    cout << endl;
    
    for(int i:sumb){
        cout << i << " ";
    }
    cout << endl;
    int sum = 0;
    int diff;
    int i=0;
    int cnt;

    while(i<a.size()){
        sum = 0;
        diff = sumMax - suma[i];
        auto it = lower_bound(sumb.begin(),sumb.end(),diff)-1;
        sum = suma[i] + *it;
        if(sum > sumMax){
            break;
        }
        else{
            cnt = 0;
        }
        cout << i << " " << it - sumb.begin() << endl;
        cnt = i + 1 + (it - sumb.begin()) + 1;
        // cout << cnt << endl;    
        i++;
    }
    cout << cnt << endl;
}