#include<iostream>
using namespace std;
class MinMax{
    public:
    int mini;
    int maxi;
};
MinMax* findMinMax(int arr[],int start,int end){
    MinMax *m,*m1,*m2;
    int mid = 0;
    // cout << start << " " << end << endl;
    if(start == end){
        m->maxi = arr[start];
        m->maxi = arr[start];
        return m;
    }
    if(end == 1+start){
        if(arr[start] > arr[end]){
            m->maxi = arr[start];
            m->mini = arr[end];
        }   
        else{
            m->maxi = arr[end];
            m->mini = arr[start];
        }
        return m;
    }
    mid = (start+end)/2;   
    m1 = findMinMax(arr,start,mid);
    m2 = findMinMax(arr,mid+1,end);
    if(m1->maxi > m2->maxi){
        m->maxi = m1->maxi;
    }
    else{
        m->maxi = m2->maxi;
    }

    if(m1->mini < m2->mini){
        m->mini = m1->mini;
    }
    else{
        m->mini = m2->mini;
    }
    return m;

}
int main(){
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int n = sizeof(arr)/sizeof(arr[0]);
    MinMax *a = findMinMax(arr,0,n-1);
    cout << " je " << endl; 
    cout << a->mini << " " << a->maxi << endl;

}