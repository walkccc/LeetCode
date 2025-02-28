class Solution:
  def maximumDetonation(self, bombs: list[list[int]]) -> int:
    n = len(bombs)
    ans = 0
    graph = [[] for _ in range(n)]

    for i, (xi, yi, ri) in enumerate(bombs):
      for j, (xj, yj, rj) in enumerate(bombs):
        if i == j:
          continue
        if ri**2 >= (xi - xj)**2 + (yi - yj)**2:
          graph[i].append(j)

    def dfs(u: int, seen: set[int]) -> None:
      for v in graph[u]:
        if v in seen:
          continue
        seen.add(v)
        dfs(v, seen)

    for i in range(n):
      seen = set([i])
      dfs(i, seen)
      ans = max(ans, len(seen))

    return ans
