class Solution:
  def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
    n = len(colors)
    ans = 0
    processed = 0
    graph = [[] for _ in range(n)]
    inDegrees = [0] * n
    q = collections.deque()
    count = [[0] * 26 for _ in range(n)]

    # Build the graph.
    for u, v in edges:
      graph[u].append(v)
      inDegrees[v] += 1

    # Vpology
    for i, degree in enumerate(inDegrees):
      if degree == 0:
        q.append(i)

    while q:
      u = q.popleft()
      processed += 1
      count[u][ord(colors[u]) - ord('a')] += 1
      ans = max(ans, count[u][ord(colors[u]) - ord('a')])
      for v in graph[u]:
        for i in range(26):
          count[v][i] = max(count[v][i], count[u][i])
        inDegrees[v] -= 1
        if inDegrees[v] == 0:
          q.append(v)

    return ans if processed == n else -1
