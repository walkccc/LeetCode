class Solution:
  def minimumChanges(self, s: str, k: int) -> int:
    n = len(s)
    # factors[i] := factors of i
    factors = self._getFactors(n)
    # cost[i][j] := changes to make s[i..j] a semi-palindrome
    cost = self._getCost(s, n, factors)
    # dp[i][j] := the minimum changes to split s[i:] into j valid parts
    dp = [[n] * (k + 1) for _ in range(n + 1)]

    dp[n][0] = 0

    for i in range(n - 1, -1, -1):
      for j in range(1, k + 1):
        for l in range(i + 1, n):
          dp[i][j] = min(dp[i][j], dp[l + 1][j - 1] + cost[i][l])

    return dp[0][k]

  def _getFactors(self, n: int) -> List[List[int]]:
    factors = [[1] for _ in range(n + 1)]
    for d in range(2, n):
      for i in range(d * 2, n + 1, d):
        factors[i].append(d)
    return factors

  def _getCost(self, s: str, n: int, factors: List[List[int]]) -> List[List[int]]:
    cost = [[0] * n for _ in range(n)]
    for i in range(n):
      for j in range(i + 1, n):
        length = j - i + 1
        minCost = length
        for d in factors[length]:
          minCost = min(minCost, self._getCostD(s, i, j, d))
        cost[i][j] = minCost
    return cost

  def _getCostD(self, s: str, i: int, j: int, d: int) -> int:
    """Returns the cost to make s[i..j] a semi-palindrome of `d`."""
    cost = 0
    for offset in range(d):
      l = i + offset
      r = j - d + 1 + offset
      while l < r:
        if s[l] != s[r]:
          cost += 1
        l += d
        r -= d
    return cost
