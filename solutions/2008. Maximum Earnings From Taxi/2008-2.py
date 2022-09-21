class Solution:
  def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
    endToStartAndEarns = [[] for _ in range(n + 1)]
    # dp[i] := max dollars you can earn starting at i
    dp = [0] * (n + 1)

    for start, end, tip in rides:
      earn = end - start + tip
      endToStartAndEarns[end].append((start, earn))

    for i in range(1, n + 1):
      dp[i] = dp[i - 1]
      for start, earn in endToStartAndEarns[i]:
        dp[i] = max(dp[i], dp[start] + earn)

    return dp[n]
