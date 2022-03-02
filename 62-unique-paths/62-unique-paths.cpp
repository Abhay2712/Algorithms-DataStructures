class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>mat(m,vector<int>(n,-1));
        return subfun(m-1,n-1,mat);
        
    }
    
    int subfun(int i,int j,vector<vector<int>>&mat){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(mat[i][j]!=-1) return mat[i][j];
        
        int up=subfun(i-1,j,mat);
        int left=subfun(i,j-1,mat);
        return mat[i][j]=up+left;
        
    }
    
};