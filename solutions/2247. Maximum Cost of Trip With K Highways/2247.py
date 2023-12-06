class Solution:
  def maximumCost(self, n: int, highways: List[List[int]], k: int) -> int:
    if k + 1 > n:
      return -1

    graph = [[] for _ in range(n)]

    for u, v, w in highways:
      graph[u].append((v, w))
      graph[v].append((u, w))

    @functools.lru_cache(None)
    def dp(u: int, mask: int) -> int:
      """
      Returns the maximum cost of trip starting from u, where `mask` represents
      the visited cities.
      """
      if mask.bit_count() == k + 1:
        return 0

      ans = -1
      for v, w in graph[u]:
        if mask >> v & 1:
          continue
        res = dp(v, mask | 1 << v)
        if res != -1:
          ans = max(ans, w + res)
      return ans

    return max(dp(i, 1 << i) for i in range(n))
