// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return subfun(dp,n-1,W,val,wt);
        
    }
    
    int subfun(vector<vector<int>>&dp,int i,int W,int val[],int wt[]){
        if(i==0){
            if(wt[0]<=W) return val[0]*(W/wt[0]);
            return 0;
        }
        
        if(dp[i][W]!=-1) return dp[i][W];
        
        int notTake=subfun(dp,i-1,W,val,wt);
        int take=INT_MIN;
        if(wt[i]<=W) take=val[i]+subfun(dp,i,W-wt[i],val,wt);
        
        return dp[i][W]=max(take,notTake);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends