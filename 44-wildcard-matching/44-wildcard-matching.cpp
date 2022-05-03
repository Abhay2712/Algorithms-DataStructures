class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+2,vector<int>(m+2,-1));
        return subfun(n-1,m-1,s,p,dp);
    }
    
    bool subfun(int i,int j,string &s, string &p, vector<vector<int>>&dp){
        if(i<0 && j<0) return 1;
        if(i>=0 && j<0) return 0;
        if(i<0 && j>=0){
            for(int a=0;a<=j;a++){
                if(p[a]!='*') return 0;
            }
            return 1;
        } 
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==p[j] || p[j]=='?')
            return dp[i][j]=subfun(i-1,j-1,s,p,dp);
        
        if(p[j]=='*'){
            return dp[i][j]=(subfun(i-1,j,s,p,dp) || subfun(i,j-1,s,p,dp));
        }

        return dp[i][j]=0;
    }
};