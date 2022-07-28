class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return subfun(1,n,dp);
    }
    
    int subfun(int i,int j,vector<vector<int>>&dp){
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res=INT_MAX;
        for(int k=i;k<j;k++){
            int left=k+subfun(i,k-1,dp);
            int right=k+subfun(k+1,j,dp);
            res=min(res,max(left,right));   
        }
        return dp[i][j]=res;
    }
};