class Solution { // 12 ms, faster than 9.19%
public:
    int numDecodings(const string& s) {
        vector<int>memo(s.size(),0);
        return dp(s, 0,memo);
    }
    
    int dp(const string& s, int i,vector<int>&memo) {
        if (i == s.size()) return 1;
        if (memo[i] != 0) return memo[i];
        int ans = 0;
        if (s[i] != '0') // Single digit
            ans += dp(s, i+1,memo);
        if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
            ans += dp(s, i+2,memo);
        return memo[i] = ans;
    }
};