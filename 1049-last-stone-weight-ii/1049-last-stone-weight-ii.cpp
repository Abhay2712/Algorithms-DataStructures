class Solution {
public:
    int subfun(vector<int>& st, int s1,int s2,int n,vector<vector<int>> &dp){
        if(n==0)
        return dp[n][s1]=abs(s1-s2);
        if(dp[n][s1]!=-1)
            return dp[n][s1];
        return dp[n][s1]=min(subfun(st,s1+st[n-1],s2,n-1,dp),subfun(st,s1,s2+st[n-1],n-1,dp));
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> vec( n+1 , vector<int> (3001, -1));
        return subfun(stones,0,0,n,vec);
    }
};