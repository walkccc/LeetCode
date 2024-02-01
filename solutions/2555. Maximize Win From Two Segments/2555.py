class Solution:
  def maximizeWin(self, prizePositions: List[int], k: int) -> int:
    ans = 0
    # dp[i] := the maximum number of prizes to choose the first i
    # `prizePositions`
    dp = [0] * (len(prizePositions) + 1)

    j = 0
    for i, prizePosition in enumerate(prizePositions):
      while prizePosition - prizePositions[j] > k:
        j += 1
      covered = i - j + 1
      dp[i + 1] = max(dp[i], covered)
      ans = max(ans, dp[j] + covered)

    return ans
