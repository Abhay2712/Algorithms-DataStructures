class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return mazeObstaclesUtil(m-1,n-1,obstacleGrid,dp);
        
    }
    
    int mazeObstaclesUtil(int i, int j, vector<vector<int>>&maze, vector<vector<int>>&dp) {
      if(i>=0 && j>=0 && maze[i][j]==1) return 0; 
      if(i==0 && j == 0) return 1;
      if(i<0 || j<0) return 0;
      if(dp[i][j]!=-1) return dp[i][j];

      int up = mazeObstaclesUtil(i-1,j,maze,dp);
      int left = mazeObstaclesUtil(i,j-1,maze,dp);

      return dp[i][j] = up+left;
    }
};