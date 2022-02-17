#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    // int n = 10;
    // vector<int> res;
    // res.push_back(0);
    // res.push_back(1);
    // res.push_back(1);

    // vector<int> even;
    // vector<int> odd;
    // int k = 0;
    // for(int i=3;k<n;i++){
    //     res.push_back(res[i/2] + i%2);
    //     if(res[i] == 2){
    //         k++;
    //         even.push_back(i);
    //     }
    // }
    // res.clear();
    // res.push_back(0);
    // res.push_back(1);
    // res.push_back(1);
    // k = 0;
    // for(int i=3;k<n;i++){
    //     res.push_back(res[i/2] + i%2);
    //     if(res[i] == 3){
    //         k++;
    //         odd.push_back(i);
    //     }
    // }
    // // for(int i=0;i<even.size();i++){
    // //     cout << i << "- " << even[i] << endl;
    // // }
    // // cout << "odd" << endl;
    // // for(int i=0;i<odd.size();i++){
    // //     cout << i << "- " << odd[i] << endl;
    // // }


    // int ourOdd = 1+(n-1)*2;
    // int ourEven = 2+(n-1)*2;

    // int paraOdd = odd[n-1];
    // int paraEven = even[n-1];
    // cout << ourOdd << " " << " "<<ourEven << " " << paraOdd << " " << paraEven  << " "<< endl;
    // cout << (paraOdd+paraEven) - (ourOdd + ourEven) << endl;
    

    // vector<vector<int>> inputs= {{0,4},{6,3},{1,5},{6,4},{7,2}};
    // int N = 10;
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<2;j++){
    //         inputs[1] = inputs[0]+inputs[1];

    //     }
    // }

    // vector<vector<int>> fish = {{1,1,1},{1,1,2},{1,2,3},{2,1,2}};
    // // vector<vector<int>> fish = {{1,1,1}};
    // int N = 2;
    // int M = 3;
    // vector<int> power(N+1,0);
    // vector<int> res(M+1,0);
    // vector<int> eat(N+1,0);
    // for(int i=0;i<fish.size();i++){
    //     if(fish[i][0] == 1){
    //         power[fish[i][1]] ++;
    //         res[fish[i][2]] = fish[i][1];
    //         eat[fish[i][1]] = fish[i][2];
    //     }
    //     else if(fish[i][0] == 2){
    //         if(power[fish[i][1]] > power[fish[i][2]]){
    //             power[fish[i][1]]++;
    //             eat[fish[i][1]] = eat[fish[i][2]];
    //             res[eat[fish[i][1]]] = fish[i][1];
    //         }
    //     }
    // }
    // // for(int i:power){
    // //     cout << i << " ";
    // // }
    // // cout << endl;
    // // for(int i:res){
    // //     cout << i << " ";
    // // }
    // // cout << endl;

    // vector<int> ans;
    // for(int i=1;i<res.size();i++){
    //     ans.push_back(res[i]);
    // }
    // return ans;
    // // for(int i:ans){
    // //     cout << i << " ";
    // // }
    // // cout << endl;

    vector<int> res = {8,10};
vector<int> ans;
    int start = res[0];
    int end = res[1];
    for(int i=start;i<=end;i++){
        ans.push_back(i);
    }
    int n = 2;
    int cnt = ans.size();
    for(int i=0;i<ans.size();i++){
        int k = 1;
        for(int j =i;j<ans.size();j++){
            k++;
            if(k==n){
                cnt ++;
                k = 1;
            }
        }
    }
    cout << cnt << endl;

}