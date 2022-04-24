class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return countUtil(s,t,n-1,m-1,dp);
    }
    int prime=1e9+7;
    int countUtil(string &s, string &t,int i,int j,vector<vector<int>>&dp ){
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
    
        if(s[i]==t[j]){
            int leaveOne = countUtil(s,t,i-1,j-1,dp);
            int stay = countUtil(s,t,i-1,j,dp);
        
            return dp[i][j] = (leaveOne + stay)%prime;
        }
    
        else{
            return dp[i][j] = countUtil(s,t,i-1,j,dp);
        }
    }
};