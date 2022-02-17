#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
/*the formula for cataline number is 2nCn.
It is used to represent in how many ways a bst can be made from n number of nodes.*/

int main(){
    int N=5;
    int *catalan = new int[N+1];
    catalan[0] = 1;
    // catalan[1] = 1;
    for(int i=1;i<=N;i++){
        catalan[i] = 0;
        for(int j=0;j<i;j++){
            catalan[i] += catalan[j]*catalan[i-j-1];
            /*The for a ith node the catalan number is in how many ways roght subtree can be
            rearranged * in how many ways left can be arranged i.e left ->j nad right ->i-j*/
        }
    }

    for(int i=0;i<=N;i++){
        cout << catalan[i] << " ";
    }
    cout << endl;

}