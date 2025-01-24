class Solution:
  def minimumCoins(self, prices: list[int]) -> int:
    n = len(prices)
    ans = math.inf
    # Stores (dp[i], i), where dp[i] := the minimum number of coins to acquire
    # fruits[i:] (0-indexed) in ascending order.
    minQ = collections.deque([(0, n)])

    for i in range(n - 1, -1, -1):
      while minQ and minQ[0][1] > (i + 1) * 2:
        minQ.popleft()
      ans = prices[i] + minQ[0][0]
      while minQ and minQ[-1][0] >= ans:
        minQ.pop()
      minQ.append((ans, i))

    return ans
