class Solution:
  def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
    ans = 0
    graph = [[] for _ in range(len(values))]
    # (node, quality, remainingTime, seen)
    q = collections.deque([(0, values[0], maxTime, {0})])

    for u, v, time in edges:
      graph[u].append((v, time))
      graph[v].append((u, time))

    while q:
      u, quality, remainingTime, seen = q.popleft()
      if u == 0:
        ans = max(ans, quality)
      for v, time in graph[u]:
        if time <= remainingTime:
          q.append(
              (v, quality + values[v] * (v not in seen), remainingTime - time, seen | set([v])))

    return ans
