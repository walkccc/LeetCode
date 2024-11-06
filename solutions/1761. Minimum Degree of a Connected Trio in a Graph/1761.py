class Solution:
  def minTrioDegree(self, n: int, edges: list[list[int]]) -> int:
    ans = math.inf
    graph = [set() for _ in range(n)]
    degrees = [0] * n

    for u, v in edges:
      u -= 1
      v -= 1
      # Store the mapping from `min(u, v)` to `max(u, v)` to speed up.
      graph[min(u, v)].add(max(u, v))
      degrees[u] += 1
      degrees[v] += 1

    for u in range(n):
      for v in graph[u]:
        for w in graph[u]:
          if w in graph[v]:
            ans = min(ans, degrees[u] + degrees[v] + degrees[w] - 6)

    return -1 if ans == math.inf else ans
