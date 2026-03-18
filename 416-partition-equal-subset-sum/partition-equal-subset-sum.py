class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total%2:
            return False

        target= total//2
        dp = [True] + [False]*(target)

        for n in nums:
            for i in range(len(dp) - 1, n - 1, -1):
                if dp[i]: continue
                if dp[i-n]: dp[i] = True
                if dp[-1]: return True
        
        return False
