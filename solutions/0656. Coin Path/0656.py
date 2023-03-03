class Solution:
  def cheapestJump(self, coins: List[int], maxJump: int) -> List[int]:
    if coins[-1] == -1:
      return []

    n = len(coins)
    # dp[i] := min cost to jump from i to n - 1
    dp = [math.inf] * n
    next = [-1] * n

    def cheapestJump(i: int) -> int:
      if i == len(coins) - 1:
        dp[i] = coins[i]
        return dp[i]
      if dp[i] < math.inf:
        return dp[i]
      if coins[i] == -1:
        return math.inf

      for j in range(i + 1, min(i + maxJump + 1, n)):
        res = cheapestJump(j)
        if res == math.inf:
          continue
        cost = coins[i] + res
        if cost < dp[i]:
          dp[i] = cost
          next[i] = j

      return dp[i]

    cheapestJump(0)
    if dp[0] == math.inf:
      return []
    return self._constructPath(next, 0)

  def _constructPath(self, next: List[int], i: int) -> List[int]:
    ans = []
    while i != -1:
      ans.append(i + 1)  # 1-indexed
      i = next[i]
    return ans
