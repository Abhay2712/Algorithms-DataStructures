class Solution {
public:
    bool dfs(string &s, string &p, int i, int j,vector<vector<int>>& dp){
        
        if(i>=s.size() and j>=p.size()) return true; //if both s and p get read at the same time. Return true. We have a match.
        if(j>=p.size()) return false; //if s string hasnt been read fully but p string has been traveresed entirely, return false
        
        
        if(dp[i][j] != -1) return dp[i][j];
        
        //declaring a variable to check whether the first characters of s and p are a match or not
        bool match = i<s.size() and (s[i] == p[j] or p[j] == '.');  //a dot is a match too
        
        //checking for second character
        if((j+1)<p.size() and p[j+1] == '*'){
            bool dontTake = dfs(s,p,i,j+2,dp); //we do a j+2 because we want to get the next character and not land on the star itself
            bool take = match ? dfs(s,p,i+1,j,dp) : false; //we take only if the first characters are a match
            return dp[i][j] = take or dontTake;
        }
        
        if(match) return dp[i][j] = dfs(s,p,i+1,j+1,dp); //simple comparison without any star or dot
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return dfs(s,p,0,0,dp);
    }
};