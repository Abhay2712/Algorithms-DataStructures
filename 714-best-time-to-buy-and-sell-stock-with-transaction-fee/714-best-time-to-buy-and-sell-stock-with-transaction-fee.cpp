class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return subfun(0,1,prices,dp,fee);
    }
    
    int subfun(int i,int j,vector<int>&prices,vector<vector<int>>&dp,int fee){
        if(i>=prices.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(j)
            return dp[i][j]=max(-prices[i]+subfun(i+1,0,prices,dp,fee),subfun(i+1,1,prices,dp,fee));
            
        else
            return dp[i][j]=max(prices[i]+subfun(i+1,1,prices,dp,fee)-fee,subfun(i+1,0,prices,dp,fee));
        
    }
};