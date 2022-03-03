class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return subfun(0,0,triangle,dp,n);
    }
    
    int subfun(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp,int n){
        if(i==n-1) return triangle[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int down=subfun(i+1,j,triangle,dp,n);
        int diag=subfun(i+1,j+1,triangle,dp,n);
        return dp[i][j]=triangle[i][j]+min(down,diag);
    }
};
