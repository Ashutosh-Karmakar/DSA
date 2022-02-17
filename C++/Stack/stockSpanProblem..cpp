
// { Driver Code Starts
#include<iostream>
#include<vector>
#include<stack>
using namespace std;


 // } Driver Code Ends




class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans;
       if(n==0){
           return ans;
       }
       stack<int> s;
       s.push(0);
       ans.push_back(1);
       for(int i=1;i<n;i++){
           if(price[s.top()] > price[i]){
               ans.push_back(1);
           }
           else if(price[s.top()] <= price[i]){
               while(price[s.top()] <= price[i]){
                   if(price[s.top()] > price[i]){
                       break;
                   }
                   s.pop();
                   if(s.empty()){
                       s.push(-1);
                       break;
                   }
               }
               
               ans.push_back(i - s.top());
           }
           s.push(i);
       }
       return ans;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends