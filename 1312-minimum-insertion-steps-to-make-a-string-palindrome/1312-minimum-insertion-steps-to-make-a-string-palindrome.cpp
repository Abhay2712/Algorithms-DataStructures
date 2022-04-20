class Solution {
public:
    int minInsertions(string s1) {
        string s2=s1;
        reverse(s1.begin(),s1.end());
        int n=s1.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=n;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return n-dp[n][n];
}
        
};