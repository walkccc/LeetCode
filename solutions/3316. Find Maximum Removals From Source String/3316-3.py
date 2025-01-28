class Solution:
  def maxRemovals(
      self,
      source: str,
      pattern: str,
      targetIndices: list[int]
  ) -> int:
    m = len(source)
    n = len(pattern)
    target = set(targetIndices)
    # dp[j] := the maximum number of operations that can be performed for
    # source so far and pattern[j..n)
    dp = [-math.inf] * (n + 1)
    dp[n] = 0

    for i in reversed(range(m)):
      newDp = dp[:]
      newDp[n] = int(i in target) + dp[n]
      for j in range(n):
        pick = dp[j + 1] if source[i] == pattern[j] else -math.inf
        skip = int(i in target) + dp[j]
        newDp[j] = max(pick, skip)
      dp = newDp

    return 0 if dp[0] == -math.inf else dp[0]
