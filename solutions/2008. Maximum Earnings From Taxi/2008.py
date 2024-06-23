class Solution:
  def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
    startToEndAndEarns = [[] for _ in range(n)]
    # dp[i] := the maximum dollars you can earn starting at i
    dp = [0] * (n + 1)

    for start, end, tip in rides:
      earn = end - start + tip
      startToEndAndEarns[start].append((end, earn))

    for i in range(n - 1, 0, -1):
      dp[i] = dp[i + 1]
      for end, earn in startToEndAndEarns[i]:
        dp[i] = max(dp[i], dp[end] + earn)

    return dp[1]
