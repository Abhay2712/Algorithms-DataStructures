class Solution {
public:
    int maxi=1e9+7;
    int subfun(int i,int k,int target,vector<vector<vector<int>>>&dp){
        if(i==0 && target==0) return 1;
        if(i<0 || target<0) return 0;
        
        if(dp[i][k][target]!=-1) return dp[i][k][target];
        int sum=0;
        for(int j=1;j<=k;j++){
            sum=(sum+subfun(i-1,k,target-j,dp))%maxi;
        }
        return dp[i][k][target]=sum%maxi;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(target+1,-1)));
        return subfun(n,k,target,dp);
    }
};