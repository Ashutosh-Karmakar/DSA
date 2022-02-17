//https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
#include<iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int start = 0;
       int end = 1;
       int cur = p[start].petrol - p[start].distance;
       while(start != end || cur < 0){
        //   cout << cur << endl;
           while(cur<0 && start != end){
               cout << "hello " <<cur << " " << start << " " << end << endl;
               cur -= p[start].petrol - p[start].distance;
               start = (start+1)%n;
               
              if(start == 0)return -1;
           }
           cur = cur + (p[end].petrol - p[end].distance);
        //   cout << cur << " " << start << " " << end << endl;
            
            end = (end+1)%n;
       }
       if(cur < 0)
        return -1;
       return start;
       
      
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends
 