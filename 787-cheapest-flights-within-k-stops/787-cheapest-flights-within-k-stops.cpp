class Solution {
public:
    int dp[101][101];
	
    int dfs(vector<vector<pair<int, int>>>& adj, int src, int dst, int k) {
        if (src == dst) return 0;
        if (k <= -1) return INT_MAX;
        
        if (dp[src][k] != -1) return dp[src][k];
        
        int ans = INT_MAX;
        for (auto child : adj[src]) {
            int res = dfs(adj, child.first, dst, k-1);
            if (res != INT_MAX)
                ans = min(ans, child.second +res);
        }
        
        return dp[src][k] = ans;
    }
    
      int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        memset(dp, -1, sizeof dp);
        vector<vector<pair<int, int>>> adj(n);
        for (auto i : flights) {
            adj[i[0]].push_back(make_pair(i[1], i[2]));
        }
          
        int ans = dfs(adj, src, dst, K);  
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
    
};