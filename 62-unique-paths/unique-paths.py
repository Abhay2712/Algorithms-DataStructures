class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        @lru_cache(None)
        def paths(i, j):
            if i == m-1 and j == n-1:
                return 1  # ✅ reached destination
            
            down = paths(i+1, j) if i < m-1 else 0
            right = paths(i, j+1) if j < n-1 else 0

            return down + right

        return paths(0, 0)
        