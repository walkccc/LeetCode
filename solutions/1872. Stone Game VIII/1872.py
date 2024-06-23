class Solution:
  def stoneGameVIII(self, stones: List[int]) -> int:
    n = len(stones)
    prefix = list(itertools.accumulate(stones))
    # dp[i] := the maximum score difference the current player can get when the
    # game starts at i, i.e. stones[0..i] are merged into the value prefix[i]
    dp = [-math.inf] * n

    # Must take all when there're only two stones left.
    dp[n - 2] = prefix[-1]

    for i in reversed(range(n - 2)):
      dp[i] = max(dp[i + 1], prefix[i + 1] - dp[i + 1])

    return dp[0]
