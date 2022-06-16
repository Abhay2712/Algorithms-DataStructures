class Solution {
public:
    int dp[102][102] = {};
    int dfs(vector<int>& cuts, int i, int j) {
        if (i>j) return 0;
        
        if (!dp[i][j]) {
            dp[i][j] = INT_MAX;
            for (auto k = i; k <=j; k++)
                dp[i][j] = min(dp[i][j], cuts[j+1] - cuts[i-1] + dfs(cuts, i, k-1) + dfs(cuts, k+1, j));
        }
        return dp[i][j];
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts), end(cuts));
        return dfs(cuts, 1, cuts.size()-2);
    }
};