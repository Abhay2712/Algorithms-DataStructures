// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
int subfun(int i,int j,int cap,vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
        if(i==n || cap==0) return 0;
        
        if(dp[i][j][cap]!=-1) return dp[i][j][cap];
        
        if(j)
            return dp[i][j][cap]=max(-prices[i]+subfun(i+1,0,cap,prices,n,dp),subfun(i+1,1,cap,prices,n,dp));
            
        else
            return dp[i][j][cap]=max(prices[i]+subfun(i+1,1,cap-1,prices,n,dp),subfun(i+1,0,cap,prices,n,dp));
        
    }

int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return subfun(0,1,2,prices,n,dp);
    }
    
    

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends