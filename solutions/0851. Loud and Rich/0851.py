class Solution:
  def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
    graph = [[] for _ in range(len(quiet))]

    for u, v in richer:
      graph[v].append(u)

    @lru_cache(None)
    def dfs(node: int) -> int:
      ans = node

      for child in graph[node]:
        res = dfs(child)
        if quiet[res] < quiet[ans]:
          ans = res

      return ans

    return map(dfs, range(len(graph)))
