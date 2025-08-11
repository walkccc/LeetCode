class Solution:
  def networkBecomesIdle(
      self,
      edges: list[list[int]],
      patience: list[int],
  ) -> int:
    n = len(patience)
    ans = 0
    graph = [[] for _ in range(n)]
    q = collections.deque([0])
    dist = [math.inf] * n  # dist[i] := the distance between i and 0
    dist[0] = 0

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    while q:
      for _ in range(len(q)):
        u = q.popleft()
        for v in graph[u]:
          if dist[v] == math.inf:
            dist[v] = dist[u] + 1
            q.append(v)

    for i in range(1, n):
      numResending = (dist[i] * 2 - 1) // patience[i]
      lastResendingTime = patience[i] * numResending
      lastArrivingTime = lastResendingTime + dist[i] * 2
      ans = max(ans, lastArrivingTime)

    return ans + 1
