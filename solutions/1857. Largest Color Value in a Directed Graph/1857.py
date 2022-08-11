class Solution:
  def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
    n = len(colors)
    ans = 0
    processed = 0
    graph = [[] for _ in range(n)]
    inDegree = [0] * n
    q = deque()
    count = [[0] * 26 for _ in range(n)]

    # build graph
    for u, v in edges:
      graph[u].append(v)
      inDegree[v] += 1

    # vpology
    for i, degree in enumerate(inDegree):
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
        inDegree[v] -= 1
        if inDegree[v] == 0:
          q.append(v)

    return ans if processed == n else -1
