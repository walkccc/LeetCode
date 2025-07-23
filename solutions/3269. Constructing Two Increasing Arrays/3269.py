class Solution:
  def minLargest(self, nums1: list[int], nums2: list[int]) -> int:
    m = len(nums1)
    n = len(nums2)
    # dp[i][j] := the minimum largest number for the first i nums1 and the
    # first j nums2
    dp = [[math.inf] * (n + 1) for _ in range(m + 1)]
    dp[0][0] = 0

    def f(prev: int, num: int) -> int:
      """
      Returns the next number to fill in the array based on the previous number
      and the current number.
      """
      return prev + (2 if prev % 2 == num else 1)

    for i in range(m + 1):
      for j in range(n + 1):
        if i > 0:
          dp[i][j] = min(dp[i][j], f(dp[i - 1][j], nums1[i - 1]))
        if j > 0:
          dp[i][j] = min(dp[i][j], f(dp[i][j - 1], nums2[j - 1]))

    return dp[m][n]
