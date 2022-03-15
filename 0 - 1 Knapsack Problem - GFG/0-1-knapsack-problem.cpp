// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return subfun(dp,n-1,W,val,wt);
       
    }
    
    int subfun(vector<vector<int>>&dp,int i,int W,int val[],int wt[]){
        if(i==0){
            if(wt[0]<=W) return val[0];
            return 0;
        }
        
        if(dp[i][W]!=-1) return dp[i][W];
        
        int notTake=subfun(dp,i-1,W,val,wt);
        int take=0;
        if(wt[i]<=W) take=val[i]+subfun(dp,i-1,W-wt[i],val,wt);
        
        return dp[i][W]=max(take,notTake);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends