class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        int mini=INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
            mini=min(subfun(0,i,matrix,dp),mini);
        }
        return mini;
    }
    
    int subfun(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0 || i>=grid.size() || j>=grid[0].size()) return 1000000;
        if(i==grid.size()-1) return grid[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int bl=grid[i][j]+subfun(i+1,j-1,grid,dp);
        int b=grid[i][j]+subfun(i+1,j,grid,dp);
        int br=grid[i][j]+subfun(i+1,j+1,grid,dp);
        return dp[i][j]=min(bl,min(b,br));     
    }
};