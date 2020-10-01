class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = float('-inf')
        sum = 0

        for num in nums:
            sum += num
            ans = max(ans, sum)
            sum = max(sum, 0)

        return ans
