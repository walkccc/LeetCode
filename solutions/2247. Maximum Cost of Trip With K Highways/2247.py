class Solution:
  def maximumCost(self, n: int, highways: list[list[int]], k: int) -> int:
    if k + 1 > n:
      return -1

    graph = [[] for _ in range(n)]

    for u, v, w in highways:
      graph[u].append((v, w))
      graph[v].append((u, w))

    @functools.lru_cache(None)
    def dp(u: int, mask: int) -> int:
      """
      Returns the maximum cost of trip starting from u, where `mask` is the
      bitmask of the visited cities.
      """
      if mask.bit_count() == k + 1:
        return 0

      res = -1
      for v, w in graph[u]:
        if mask >> v & 1:
          continue
        nextCost = dp(v, mask | 1 << v)
        if nextCost != -1:
          res = max(res, w + nextCost)
      return res

    return max(dp(i, 1 << i) for i in range(n))
