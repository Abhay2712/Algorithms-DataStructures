class Solution {
public:
    int m,n,co;
    void dfs(vector<vector<int>>& grid , vector<vector<bool>>& vis , int i , int j ,int val)
    {
	// base condition to eliminate the coordinate
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || grid[i][j]!=val)
            return;
        vis[i][j] = true;
        
		// check if present on the border of the square or not
        if(i==0 || j==0 || i>=m-1 || j>=n-1)
            grid[i][j]=co;
        
		// conditon to check if their is present some differnt color square on the border of the connected component
        if((i+1<=m-1 && grid[i+1][j]!=val && !vis[i+1][j]) || (i-1>=0 && grid[i-1][j]!=val && !vis[i-1][j]) || (j+1<=n-1 && grid[i][j+1]!=val && !vis[i][j+1]) || (j-1>=0 && grid[i][j-1]!=val && !vis[i][j-1]))
            grid[i][j] = co;

        dfs(grid,vis,i+1,j,val);
        dfs(grid,vis,i,j+1,val);
        dfs(grid,vis,i,j-1,val);
        dfs(grid,vis,i-1,j,val);
        return;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();
        co = color;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        dfs(grid,vis,row,col,grid[row][col]);
        return grid;
    }
};