class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    if(subfun(i,j,grid)) count++;
                }
            }
            
        }
        return count;
    }
    
    bool subfun(int i,int j,vector<vector<int>>&grid){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
        if((i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1) && grid[i][j]==0) return 0;
        else if(grid[i][j]!=0) return 1;
        grid[i][j]='*';
        bool up=subfun(i-1,j,grid);
        bool down=subfun(i+1,j,grid);
        bool left=subfun(i,j-1,grid);
        bool right=subfun(i,j+1,grid);
        return (up && down && left && right);
    }
};