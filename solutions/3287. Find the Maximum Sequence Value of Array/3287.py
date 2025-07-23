class Solution:
  def maxValue(self, nums: list[int], k: int) -> int:
    left = self._getPossibleORs(nums, k)
    right = self._getPossibleORs(nums[::-1], k)[::-1]
    return max(a ^ b
               for i in range(k - 1, len(nums) - k)
               for a in range(128 + 1)
               for b in range(128 + 1)
               if left[i][k][a] and right[i + 1][k][b])

  def _getPossibleORs(self, nums: list[int], k: int) -> list[list[list[bool]]]:
    dp = [[[False] * (128 + 1)
          for _ in range(k + 1)]
          for _ in range(len(nums))]

    dp[0][1][nums[0]] = True

    for i in range(len(nums)):
      dp[i][0][0] = True

    for i in range(1, len(nums)):
      for j in range(1, k + 1):
        for x in range(128 + 1):
          if dp[i - 1][j][x]:
            dp[i][j][x] = True
          if dp[i - 1][j - 1][x]:
            dp[i][j][nums[i] | x] = True

    return dp
