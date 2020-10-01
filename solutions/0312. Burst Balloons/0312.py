class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)

        nums = [1] + nums + [1]
        dp = [[0] * (n + 2) for _ in range(n + 2)]

        for length in range(1, n + 1):
            for i in range(1, n - length + 2):
                j = i + length - 1
                for k in range(i, j + 1):
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1]
                                   [j] + nums[i - 1] * nums[k] * nums[j + 1])

        return dp[1][n]
