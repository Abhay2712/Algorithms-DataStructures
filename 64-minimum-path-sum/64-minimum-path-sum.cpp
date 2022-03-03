class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return subfun(m-1,n-1,grid,dp);
    }
    
    int subfun(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=subfun(i-1,j,grid,dp);
        int left=subfun(i,j-1,grid,dp);
        
        return dp[i][j]=grid[i][j]+min(up,left);
        
    }
};

//tabular method
// int minSumPath(int n, int m, vector<vector<int> > &matrix){
//     vector<vector<int> > dp(n,vector<int>(m,0));
//     for(int i=0; i<n ; i++){
//         for(int j=0; j<m; j++){
//             if(i==0 && j==0) dp[i][j] = matrix[i][j];
//             else{
                
//                 int up = matrix[i][j];
//                 if(i>0) up += dp[i-1][j];
//                 else up += 1e9;
                
//                 int left = matrix[i][j];
//                 if(j>0) left+=dp[i][j-1];
//                 else left += 1e9;
                
//                 dp[i][j] = min(up,left);
//             }
//         }
//     }
    
//     return dp[n-1][m-1];
    
// }
