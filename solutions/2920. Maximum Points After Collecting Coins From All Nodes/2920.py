class Solution:
  def maximumPoints(
      self,
      edges: list[list[int]],
      coins: list[int],
      k: int,
  ) -> int:
    kMaxCoin = 10000
    kMaxHalved = int(kMaxCoin).bit_length()
    n = len(coins)
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    @functools.lru_cache(None)
    def dfs(u: int, prev: int, halved: int) -> int:
      # All the children will be 0, so no need to explore.
      if halved > kMaxHalved:
        return 0

      val = coins[u] // (1 << halved)
      takeAll = val - k
      takeHalf = math.floor(val / 2)

      for v in graph[u]:
        if v == prev:
          continue
        takeAll += dfs(v, u, halved)
        takeHalf += dfs(v, u, halved + 1)

      return max(takeAll, takeHalf)

    return dfs(0, -1, 0)
