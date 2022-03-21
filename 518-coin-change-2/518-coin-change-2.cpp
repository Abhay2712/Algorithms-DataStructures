class Solution {
public:
    int subfun(int i,int tar,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0){
            if(tar%coins[0]==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][tar]!=-1) return dp[i][tar];
        int notPick=subfun(i-1,tar,coins,dp);
        int pick=0;
        if(tar>=coins[i]){
            pick=subfun(i,tar-coins[i],coins,dp);
        }
        
        return dp[i][tar]=pick+notPick;
        
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return subfun(coins.size()-1,amount,coins,dp);
    }
};