class Solution:
    def rob(self, nums: List[int]) -> int:
        dp1 = 0
        dp2 = 0

        for num in nums:
            temp = dp1
            dp1 = max(dp1, dp2 + num)
            dp2 = temp

        return dp1
