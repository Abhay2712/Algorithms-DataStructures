class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return subfun(0,1,2,prices,n,dp);
    }
    
    int subfun(int i,int j,int cap,vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
        if(i==n || cap==0) return 0; 
        if(dp[i][j][cap]!=-1) return dp[i][j][cap];
        
        if(j)
            return dp[i][j][cap]=max(-prices[i]+subfun(i+1,0,cap,prices,n,dp),subfun(i+1,1,cap,prices,n,dp));
            
        else
            return dp[i][j][cap]=max(prices[i]+subfun(i+1,1,cap-1,prices,n,dp),subfun(i+1,0,cap,prices,n,dp));
        
    }
};