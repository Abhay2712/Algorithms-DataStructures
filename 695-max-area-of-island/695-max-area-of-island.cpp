class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int count=0;
                if(grid[i][j]==1) floodfill(i,j,grid,count,maxi);
            }
        }
        return maxi;
    }
    
    void floodfill(int i,int j,vector<vector<int>>& grid,int &count,int &maxi){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() ) return;
        if(grid[i][j]==0) return;
        grid[i][j]=0;
        count++;
        maxi=max(count,maxi);
        floodfill(i+1,j,grid,count,maxi);
        floodfill(i,j+1,grid,count,maxi);
        floodfill(i-1,j,grid,count,maxi);
        floodfill(i,j-1,grid,count,maxi);
    }
};