class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        summ = sum(nums)

        if summ < S or (summ + S) & 1:
            return 0

        def subsetSum(s: int) -> int:
            dp = [1] + [0] * summ

            for num in nums:
                for w in range(summ, num - 1, -1):
                    dp[w] += dp[w - num]

            return dp[s]

        return subsetSum((summ + S) // 2)
