class Solution {
public:
    int minimum_area(vector<int> &A,int start,int end,vector<vector<int>>&dp){
        if(start+1==end) return 0;
        
        if(dp[start][end]!=0) return dp[start][end];
        
        int ans=INT_MAX;
        for(int cut=start+1;cut<end;cut++){
            
            int leftAns=minimum_area(A,start,cut,dp);
            int rightAns=minimum_area(A,cut,end,dp);
            
            int myAns=leftAns+(A[start]*A[cut]*A[end])+rightAns;
            
            ans=min(ans,myAns);
        }
        
        return dp[start][end]=ans;
    }
    int minScoreTriangulation(vector<int>& A) {
        int n=A.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        return minimum_area(A,0,n-1,dp);
    }
};