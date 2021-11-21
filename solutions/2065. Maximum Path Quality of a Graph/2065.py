class Solution:
  def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
    n = len(values)

    self.ans = 0
    graph = [[] for _ in range(n)]
    seen = [0] * n
    seen[0] = 1

    for u, v, time in edges:
      graph[u].append((v, time))
      graph[v].append((u, time))

    def dfs(u: int, quality: int, remainingTime: int):
      if u == 0:
        self.ans = max(self.ans, quality)
      for v, time in graph[u]:
        if time > remainingTime:
          continue
        newQuality = quality + values[v] * (seen[v] == 0)
        seen[v] += 1
        dfs(v, newQuality, remainingTime - time)
        seen[v] -= 1

    dfs(0, values[0], maxTime)

    return self.ans
