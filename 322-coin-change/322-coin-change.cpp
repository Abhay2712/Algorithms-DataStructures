class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int total=0;
        int ans=subfun(coins,coins.size()-1,amount,dp,total);
        if(total==0)
            return -1;
        return ans;
        
    }
    
    int subfun(vector<int>&coins,int i,int target,vector<vector<int>>&dp,int &total){
        if(i==0) {
            if(target%coins[0]==0) {
                total+=1;
                return target/coins[0];
            }
            return 1e9;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
        int pick=1e9;
        if(coins[i]<=target)        
            pick=1+subfun(coins,i,target-coins[i],dp,total);
        
        int notPick=subfun(coins,i-1,target,dp,total);
        
        return dp[i][target]=min(pick,notPick);
    }
};