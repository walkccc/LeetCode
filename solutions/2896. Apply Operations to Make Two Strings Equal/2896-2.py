class Solution:
  def minOperations(self, s1: str, s2: str, x: int) -> int:
    diffIndices = [i for i, (a, b) in enumerate(zip(s1, s2))
                   if a != b]
    if not diffIndices:
      return 0
    # It's impossible to make two strings equal if there are odd number of
    # differences.
    if len(diffIndices) & 1:
      return -1

    # dp[i] := the minimum cost to correct diffIndices[i:]
    dp = [math.inf] * len(diffIndices) + [0]
    dp[-2] = x / 2

    for i in reversed(range(len(diffIndices) - 1)):
      dp[i] = min(dp[i + 1] + x / 2,
                  dp[i + 2] + diffIndices[i + 1] - diffIndices[i])

    return int(dp[0])
