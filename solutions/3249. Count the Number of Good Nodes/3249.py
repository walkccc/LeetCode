class Solution:
  def countGoodNodes(self, edges: list[list[int]]) -> int:
    n = len(edges) + 1
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    ans = 0

    def dfs(u: int, prev: int) -> int:
      """Returns the size of the subtree rooted at u."""
      nonlocal ans
      size = 1
      childrenSizes = []
      for v in graph[u]:
        if v == prev:
          continue
        child_size = dfs(v, u)
        size += child_size
        childrenSizes.append(child_size)

      if not childrenSizes or all(s == childrenSizes[0]
                                  for s in childrenSizes):
        ans += 1

      return size

    dfs(0, -1)
    return ans
