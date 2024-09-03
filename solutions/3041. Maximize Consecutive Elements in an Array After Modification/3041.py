class Solution:
  def maxSelectedElements(self, nums: list[int]) -> int:
    ans = 0
    # {num: the length of the longest consecutive elements ending in num}
    dp = {}

    for num in sorted(nums):
      dp[num + 1] = dp.get(num, 0) + 1
      dp[num] = dp.get(num - 1, 0) + 1
      ans = max(ans, dp[num], dp[num + 1])

    return ans
