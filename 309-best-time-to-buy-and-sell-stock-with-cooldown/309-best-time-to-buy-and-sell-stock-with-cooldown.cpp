class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(3,-1));
        return subfun(0,1,prices,dp);
    }
    
    int subfun(int i,int j,vector<int>&prices,vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(j)
            return dp[i][j]=max(-prices[i]+subfun(i+1,0,prices,dp),subfun(i+1,1,prices,dp));
            
        else
            return dp[i][j]=max(prices[i]+subfun(i+2,1,prices,dp),subfun(i+1,0,prices,dp));
        
    }
};