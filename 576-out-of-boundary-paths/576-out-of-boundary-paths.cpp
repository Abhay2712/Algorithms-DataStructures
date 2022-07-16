class Solution {
public:
    int mod = 1e9 + 7;
    int helperFunction(int row, int col, int maxMoves, int x, int y,  int moves, vector<vector<vector<long>>> & dp){
        if(x < 0 || y < 0 || x >= row || y >= col){
            return 1;
        }
        if(moves == maxMoves){
            return 0;
        }
        if(dp[moves][x][y] != -1){
            return dp[moves][x][y] % mod;
        }
        long left,right,up,down;
        up = helperFunction(row, col, maxMoves, x, y - 1, moves + 1, dp) % mod;
        left = helperFunction(row, col, maxMoves, x - 1, y, moves + 1, dp) % mod;
        right = (helperFunction(row, col, maxMoves, x + 1, y, moves + 1, dp)) % mod;
        down = (helperFunction(row, col, maxMoves, x, y + 1, moves + 1, dp)) % mod;
        dp[moves][x][y] = up+down+left+right;
        return dp[moves][x][y] % mod;
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<long>>> dp(N + 1, vector<vector<long>> (m + 1, vector<long> (n + 1, -1)));
        dp[N][m][n] = helperFunction(m, n, N, i, j, 0, dp);
        return dp[N][m][n];
    }
};