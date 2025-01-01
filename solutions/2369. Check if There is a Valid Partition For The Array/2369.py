class Solution:
  def validPartition(self, nums: list[int]) -> bool:
    n = len(nums)
    # dp[i] := True if there's a valid partition for the first i numbers
    dp = [False] * (n + 1)
    dp[0] = True
    dp[2] = nums[0] == nums[1]

    for i in range(3, n + 1):
      dp[i] = (
          dp[i - 2] and nums[i - 2] == nums[i - 1]) or (
          dp[i - 3]
          and (
              (nums[i - 3] == nums[i - 2] and nums[i - 2] == nums[i - 1])
              or (
                  nums[i - 3] + 1 == nums[i - 2] and nums[i - 2] + 1 == nums
                  [i - 1])))

    return dp[n]
