class Solution:
  def countPairsOfConnectableServers(
      self,
      edges: list[list[int]],
      signalSpeed: int,
  ) -> list[int]:
    n = len(edges) + 1
    tree = [[] for _ in range(n)]

    for u, v, w in edges:
      tree[u].append((v, w))
      tree[v].append((u, w))

    def connectablePairsRootedAt(u: int) -> int:
      pairs = 0
      count = 0
      for v, w in tree[u]:
        childCount = dfs(v, u, w)
        pairs += count * childCount
        count += childCount
      return pairs

    def dfs(u: int, prev: int, dist: int) -> int:
      return (int(dist % signalSpeed == 0) +
              sum(dfs(v, u, dist + w)
              for v, w in tree[u]
              if v != prev))

    return [connectablePairsRootedAt(i) for i in range(n)]
