class Solution:
  def findLength(self, nums1: list[int], nums2: list[int]) -> int:
    ans = 0
    dp = [0] * (len(nums2) + 1)

    for a in reversed(nums1):
      for j, b in enumerate(nums2):  # The order is important.
        dp[j] = dp[j + 1] + 1 if a == b else 0
        ans = max(ans, dp[j])

    return ans
