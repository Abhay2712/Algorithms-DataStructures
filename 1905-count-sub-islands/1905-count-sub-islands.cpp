class Solution {
public:
    bool subfun(int i,int j,int n,int m, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(i<0 || j<0 || i>=n || j>=m || grid2[i][j]==0) return true;
        if(grid1[i][j]==0) return false;
        grid2[i][j]=0;
        bool a=subfun(i+1,j,n,m,grid1,grid2);
        bool b=subfun(i-1,j,n,m,grid1,grid2);
        bool c=subfun(i,j+1,n,m,grid1,grid2);
        bool d=subfun(i,j-1,n,m,grid1,grid2);
        return (a&&b&&c&&d);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid1[i][j]==1 && grid2[i][j]==1){
                    if(subfun(i,j,n,m,grid1,grid2)) count++;
                }
            }
        }
        return count;
    }
};