class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)

        @lru_cache()
        def buy(pos, situation):
            if pos==n:
                return 0

            if situation == 0:
                return max(-prices[pos] + buy(pos+1, 1), buy(pos+1, 0))
            
            elif situation == 1:
                return max(prices[pos] + buy(pos+1, 2), buy(pos+1, 1))

            else:
                return buy(pos+1, 0)

        return buy(0, 0)
