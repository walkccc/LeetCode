class Solution:
  def longestPath(self, parent: list[int], s: str) -> int:
    n = len(parent)
    ans = 0
    graph = [[] for _ in range(n)]

    for i in range(1, n):
      graph[parent[i]].append(i)

    def longestPathDownFrom(u: int) -> int:
      nonlocal ans
      max1 = 0
      max2 = 0

      for v in graph[u]:
        res = longestPathDownFrom(v)
        if s[u] == s[v]:
          continue
        if res > max1:
          max2 = max1
          max1 = res
        elif res > max2:
          max2 = res

      ans = max(ans, 1 + max1 + max2)
      return 1 + max1

    longestPathDownFrom(0)
    return ans
