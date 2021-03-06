class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
       int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
    
    
    
    
    
    
    
// Memoization solution
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return subfun(text1,text2,n-1,m-1,dp);
//     }
    
//     int subfun(string &str1,string &str2,int i,int j,vector<vector<int>>&dp){
 
//         if(i<0 || j<0){
//             return 0;
//         }
        
//         if(dp[i][j]!=-1) return dp[i][j];
//         int pick=0,notPick=0;
        
//         if(str1[i]==str2[j]){
//             return dp[i][j]=1+subfun(str1,str2,i-1,j-1,dp);
//         }
        
//         else{
//             return dp[i][j]=max(subfun(str1,str2,i-1,j,dp),subfun(str1,str2,i,j-1,dp));
//         }        
//     }
// };