class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
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
        int len = dp[n][m];
  int i = n;
  int j = m;

  int index = len - 1;
  string ans = "";

  while (i > 0 && j > 0) {
    if (text1[i - 1] == text2[j - 1]) {
      ans += text1[i-1];
      index--;
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
        ans += text1[i-1];
        i--;
    } else {
        ans += text2[j-1];
        j--;
    }
  }
  
  //Adding Remaing Characters - Only one of the below two while loops will run 
  
  while(i>0){
      ans += text1[i-1];
      i--;
  }
  while(j>0){
      ans += text2[j-1];
      j--;
  }

  reverse(ans.begin(),ans.end());
  
  return ans;
}
};