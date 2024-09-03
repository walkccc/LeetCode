class Solution:
  def minimumTotalPrice(self, n: int, edges: list[list[int]], price: list[int],
                        trips: list[list[int]]) -> int:
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    # count[i] := the number of times i is traversed
    count = [0] * n

    def dfsCount(u: int, prev: int, end: int, path: list[int]) -> None:
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
      """
      Returns the minimum price sum for the i-th node, where its parent is
      halved parent or not halved not.
      """
      sumWithFullNode = price[u] * count[u] + sum(dfs(v, u, False)
                                                  for v in graph[u]
                                                  if v != prev)
      if parentHalved:  # Can't halve this node if its parent was halved.
        return sumWithFullNode
      sumWithHalvedNode = (price[u] // 2) * count[u] + sum(dfs(v, u, True)
                                                           for v in graph[u]
                                                           if v != prev)
      return min(sumWithFullNode, sumWithHalvedNode)

    return dfs(0, -1, False)
