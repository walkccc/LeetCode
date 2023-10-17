class Solution:
  def minimumTotalPrice(self, n: int, edges: List[List[int]], price: List[int],
                        trips: List[List[int]]) -> int:
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    # count[i] := # times i is traversed
    count = [0] * n

    def dfsCount(u: int, prev: int, end: int, path: List[int]) -> None:
      path.append(u)
      if u == end:
        for i in path:
          count[i] += 1
        return
      for v in graph[u]:
        if v != prev:
          dfsCount(v, u, end,  path)
      path.pop()

    for start, end in trips:
      dfsCount(start, -1, end, [])

    @functools.lru_cache(None)
    def dfs(u: int, prev: int, parentHalved: bool) -> int:
      sumWithFullNode = price[u] * count[u]
      for v in graph[u]:
        if v != prev:
          sumWithFullNode += dfs(v, u, False)

      if parentHalved:  # Can't halve this node if parent was halved.
        return sumWithFullNode

      sumWithHalvedNode = (price[u] // 2) * count[u]
      for v in graph[u]:
        if v != prev:
          sumWithHalvedNode += dfs(v, u, True)

      return min(sumWithFullNode, sumWithHalvedNode)

    return dfs(0, -1, False)
