class Solution:
  def minimumCoins(self, prices: list[int]) -> int:
    n = len(prices)
    # Stores (dp[i], i), where dp[i] is the minimum number of coins to acquire
    # fruits[i:] (0-indexed).
    minHeap = [(0, n)]
    ans = 0

    for i in range(n - 1, -1, -1):
      while minHeap and minHeap[0][1] > (i + 1) * 2:
        heapq.heappop(minHeap)
      ans = prices[i] + minHeap[0][0]
      heapq.heappush(minHeap, (ans, i))

    return ans
