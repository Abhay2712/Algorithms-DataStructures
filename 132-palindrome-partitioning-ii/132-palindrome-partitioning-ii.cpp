class Solution {
public:
    int subfun(int i,int n,string &s,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX,cost;
        for(int j=i;j<n;j++){
            if(isPal(i,j,s)){
                cost=1+subfun(j+1,n,s,dp);
                mini=min(cost,mini);
            }
        }
        return dp[i]=mini;
    }
    
    int minCut(string s) {
        vector<int>dp(s.size()+1,-1);
        return subfun(0,s.size(),s,dp)-1;
    }
    
    bool isPal(int i,int j,string &s){
        while(i<j){
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
};