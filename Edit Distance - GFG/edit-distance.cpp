// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string word1, string word2) {
        // Code here
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return subfun(word1,word2,n-1,m-1,dp);
    }
    
    int subfun(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if (dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return subfun(s1,s2,i-1,j-1,dp);
        else{
        int del=1+subfun(s1,s2,i-1,j,dp);
        int ins=1+subfun(s1,s2,i,j-1,dp);
        int rep=1+subfun(s1,s2,i-1,j-1,dp);
        return dp[i][j]=min(del,min(ins,rep));
        }
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends