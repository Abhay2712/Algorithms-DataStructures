class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return subfun(0,m,n,strs,dp);
    }
    
    int subfun(int i, int m, int n,vector<string>& strs,vector<vector<vector<int>>>&dp){
        if(i>=strs.size()) return 0;
        
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        
        int one = count(strs[i].begin(), strs[i].end(), '1');
        int zero= strs[i].size()-one;
        
        if(m-zero>=0 && n-one>=0) 
            return dp[i][m][n]=max(1+subfun(i+1,m-zero, n-one,strs,dp),subfun(i+1,m, n,strs,dp));
        else return dp[i][m][n]=subfun(i+1,m, n,strs,dp);
    }
};