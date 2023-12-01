class Solution:
  def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
    ans = 0
    graph = [[] for _ in range(n)]

    def dfs(u: int, prev: int) -> int:
      nonlocal ans
      treeSum = values[u]

      for v in graph[u]:
        if v != prev:
          treeSum += dfs(v, u)

      if treeSum % k == 0:
        ans += 1
      return treeSum

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    dfs(0, -1)
    return ans
