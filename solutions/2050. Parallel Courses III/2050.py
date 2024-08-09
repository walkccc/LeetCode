class Solution:
  def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
    graph = [[] for _ in range(n)]
    inDegrees = [0] * n
    dist = time.copy()

    # Build the graph.
    for a, b in relations:
      u = a - 1
      v = b - 1
      graph[u].append(v)
      inDegrees[v] += 1

    # Perform topological sorting.
    q = collections.deque([i for i, d in enumerate(inDegrees) if d == 0])

    while q:
      u = q.popleft()
      for v in graph[u]:
        dist[v] = max(dist[v], dist[u] + time[v])
        inDegrees[v] -= 1
        if inDegrees[v] == 0:
          q.append(v)

    return max(dist)
