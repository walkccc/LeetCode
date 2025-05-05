class Solution:
  def loudAndRich(self, richer: list[list[int]], quiet: list[int]) -> list[int]:
    graph = [[] for _ in range(len(quiet))]

    for v, u in richer:
      graph[u].append(v)

    @functools.lru_cache(None)
    def dfs(u: int) -> int:
      ans = u

      for v in graph[u]:
        res = dfs(v)
        if quiet[res] < quiet[ans]:
          ans = res

      return ans

    return map(dfs, range(len(graph)))
