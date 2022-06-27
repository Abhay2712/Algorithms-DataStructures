class Solution {
public:
    
    pair<int, int> f(int i, int j, int K, vector<int> &stones, vector<int> &sum, vector<vector<pair<int, int>>> &dp) {
        if (dp[i][j].first != -1) return dp[i][j];
        int ws = j - i + 1;
        if (ws < K) return dp[i][j] = {0, ws}; // you can't merge stones if they are of size less than K
        if (ws == K) return dp[i][j] = {sum[j] - (i > 0 ? sum[i - 1]: 0), 1};
        auto res = make_pair(INT_MAX, -1);
        for (int spix = i; spix < j; spix ++) { // spix inclusive
            auto [mlc, mlws] = f(i, spix, K, stones, sum, dp);
            auto [mrc, mrws] = f(spix + 1, j, K, stones, sum, dp);
            if (mlc != INT_MAX && mrc != INT_MAX && mlws + mrws <= K) {
                int newcost = mlc + mrc; 
                int newsize = mlws + mrws;
                if (newsize == K) newcost += sum[j] - (i > 0 ? sum[i - 1]: 0), newsize = 1;
                if (newcost < res.first) res = {newcost, newsize};
            }
        }
        return dp[i][j] = res;
    }
    
    
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        vector<int> sum(n, 0);
        sum[0] = stones[0];
        for (int i = 1; i < n; i ++) sum[i] = sum[i - 1] + stones[i];
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n, {-1, -1}));
        auto [c, s] = f(0, n - 1, K, stones, sum, dp);
        return s == 1 ? c : -1;
    }
};