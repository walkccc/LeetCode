class Solution:
  def allPathsSourceTarget(self, graph: list[list[int]]) -> list[list[int]]:
    ans = []

    def dfs(u: int, path: list[int]) -> None:
      if u == len(graph) - 1:
        ans.append(path)
        return

      for v in graph[u]:
        dfs(v, path + [v])

    dfs(0, [0])
    return ans
