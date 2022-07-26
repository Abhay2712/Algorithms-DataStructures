// a --> e  i  u             dp[i][0] = dp[i-1][1] + dp[i-1][2] + dp[i-1][4]
// e --> i  a                dp[i][1] = dp[i-1][2] + dp[i-1][0]
// i --> e  o                dp[i][2] = dp[i-1][1] + dp[i-1][3]
// o --> i                   dp[i][3] = dp[i-1][2]
// u --> o  i                dp[i][4] = dp[i-1][3] + dp[i-1][2]

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long int> > dp(n, vector<long long int>(5,0));
        int mod = 1e9+7;
        
        for(int i=0;i<5;i++){
            dp[0][i]=1;
        }
        
        for(int i=1;i<n;i++){
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4])%mod;
            
            dp[i][1] = (dp[i-1][2] + dp[i-1][0])%mod;
            
            dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod;
            
            dp[i][3] = (dp[i-1][2])%mod;
            
            dp[i][4] = (dp[i-1][3] + dp[i-1][2])%mod;
        }
        
        long long int sum=0;
        
        for(int i=0;i<5;i++){
            sum+=dp[n-1][i];
            sum%=mod;
        }
        
        return sum;
    }
};