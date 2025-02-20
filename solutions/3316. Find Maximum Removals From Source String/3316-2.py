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
    # dp[i][j] := the maximum number of operations that can be performed for
    # source[i..m) and pattern[j..n)
    dp = [[-math.inf] * (n + 1) for _ in range(m + 1)]
    dp[m][n] = 0

    for i in reversed(range(m)):
      dp[i][n] = int(i in target) + dp[i + 1][n]
      for j in reversed(range(n)):
        pick = dp[i + 1][j + 1] if source[i] == pattern[j] else -math.inf
        skip = int(i in target) + dp[i + 1][j]
        dp[i][j] = max(pick, skip)

    return 0 if dp[0][0] == -math.inf else dp[0][0]
