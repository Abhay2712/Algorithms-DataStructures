class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return subfun(0,0,triangle,dp,n);
    }
    
    int subfun(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp,int n){
        if(i==n-1) return triangle[i][j];   //here we going from 0 to n
        
        if(dp[i][j]!=-1) return dp[i][j];
        int down=subfun(i+1,j,triangle,dp,n);
        int diag=subfun(i+1,j+1,triangle,dp,n);
        return dp[i][j]=triangle[i][j]+min(down,diag);
    }
};

//tabulation
// int minimumPathSum(vector<vector<int> > &triangle, int n){
//     vector<vector<int> > dp(n,vector<int>(n,0));
    
//     for(int j=0;j<n;j++){
//         dp[n-1][j] = triangle[n-1][j];
//     }
    
//     for(int i=n-2; i>=0; i--){
//         for(int j=i; j>=0; j--){
            
//             int down = triangle[i][j]+dp[i+1][j];
//             int diagonal = triangle[i][j]+dp[i+1][j+1];
            
//             dp[i][j] = min(down, diagonal);
//         }
//     }
    
//     return dp[0][0];
    
// }