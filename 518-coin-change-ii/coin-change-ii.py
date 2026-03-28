class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
        n = len(coins)

        @lru_cache(None)
        def count(pos, remaining):
            if remaining == 0:
                return 1
            if remaining < 0 or pos == n:
                return 0

            return count(pos, remaining - coins[pos]) + count(pos + 1, remaining)

        return count(0, amount)
