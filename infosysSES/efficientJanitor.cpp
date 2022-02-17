#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<double> res;
    int n;
    cin>>n;
    double x;
    for(int i=0;i<n;i++){
        cin >> x;
        res.push_back(x);
    }
    sort(res.begin(),res.end());
    int s = 0;
    int l = n-1;
    int k =3;
    while(s<l){ 

        if(res[s] + res[l] > 3){
            cout << res[l] << endl;
            l--;
        }
        if(res[s] + res[l] <= 3){
            cout << res[s] << " " << res[l] << endl;
            l--;
            s++;
        }
    }

}