class Solution:
  def longestIdealString(self, s: str, k: int) -> int:
    # dp[i] := the longest subsequence that ends in ('a' + i)
    dp = [0] * 26

    for c in s:
      i = string.ascii_lowercase.index(c)
      dp[i] = 1 + self._getMaxReachable(dp, i, k)

    return max(dp)

  def _getMaxReachable(self, dp: list[int], i: int, k: int) -> int:
    first = max(0, i - k)
    last = min(25, i + k)
    maxReachable = 0
    for j in range(first, last + 1):
      maxReachable = max(maxReachable, dp[j])
    return maxReachable
