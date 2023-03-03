class Solution:
  def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
    graph = [[] for _ in range(len(quiet))]

    for u, v in richer:
      graph[v].append(u)

    @functools.lru_cache(None)
    def dfs(u: int) -> int:
      ans = u

      for v in graph[u]:
        res = dfs(v)
        if quiet[res] < quiet[ans]:
          ans = res

      return ans

    return map(dfs, range(len(graph)))
