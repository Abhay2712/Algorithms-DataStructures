class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
        n = len(coins)

        @lru_cache(None)
        def count(pos, remaining):
            # ✅ best base cases
            if remaining == 0:
                return 1
            if remaining < 0 or pos == n:
                return 0

            # skip current coin
            skip = count(pos + 1, remaining)

            # take current coin (stay at same index)
            take = count(pos, remaining - coins[pos])

            return take + skip

        return count(0, amount)
