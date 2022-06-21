class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(subfun(0,cost,dp),subfun(1,cost,dp));
    }
    
    int subfun(int i,vector<int>& cost,vector<int>&dp){
        if(i>=cost.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        return dp[i]=min(cost[i]+subfun(i+1,cost,dp),cost[i]+subfun(i+2,cost,dp));
    }
};