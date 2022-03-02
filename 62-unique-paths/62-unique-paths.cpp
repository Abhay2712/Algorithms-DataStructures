class Solution {
public:
int uniquePaths(int m, int n){
    vector<vector<int> > dp(m,vector<int>(n,-1));
    return countWaysUtil(m,n,dp);
    
}
    
int countWaysUtil(int m, int n, vector<vector<int> > &dp) {
  for(int i=0; i<m ;i++){
      for(int j=0; j<n; j++){
          
          //base condition
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
      }
  }
  
  return dp[m-1][n-1];
}
    
};

//memoization method
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>mat(m,vector<int>(n,-1));
//         return subfun(m-1,n-1,mat);
        
//     }
    
//     int subfun(int i,int j,vector<vector<int>>&mat){
//         if(i==0 && j==0) return 1;
//         if(i<0 || j<0) return 0;
        
//         if(mat[i][j]!=-1) return mat[i][j];
        
//         int up=subfun(i-1,j,mat);
//         int left=subfun(i,j-1,mat);
//         return mat[i][j]=up+left;
        
//     }