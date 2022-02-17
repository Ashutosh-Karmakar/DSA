#include<iostream>
#include<algorithm>

using namespace std;

struct meeting{
    int s;
    int e;
    int p;
};



//Function to find the maximum number of meetings that can
//be performed in a meeting room.
bool comparator(struct meeting p1 ,meeting p2){
    if(p1.e < p2.e){
        return true;
    }
    else if(p1.e > p2.e){
        return false;
    }
    else if(p1.p < p2.p){
        return true;
    }
    return false;
}
int maxMeetings(int start[],int last[], int n)
{
    // Your code
    struct meeting meet[n];
    
    for(int i=0;i<n;i++){
        meet[i].s = start[i];
        meet[i].e = last[i];
        meet[i].p = i+1;
    }
    // sort(vect.begin(), vect.end(), sortbysec);
    sort(meet, meet+n, comparator);
    int endtime = meet[0].e;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(endtime < meet[i].s){
            cnt ++;
            endtime = meet[i].e;
        }
        else{
            continue;
        }
        
    }
    return cnt;
}
int main(){
    int start[] = {1,3,0,5,8,5};
    int end[]   = {2,4,6,7,9,9};
    int N = 6;
    
    cout << maxMeetings(start,end,N);
}