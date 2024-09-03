class Solution:
  def minimumSemesters(self, n: int, relations: list[list[int]]) -> int:
    ans = 0
    graph = [[] for _ in range(n)]
    inDegrees = [0] * n

    # Build the graph.
    for u, v in relations:
      graph[u - 1].append(v - 1)
      inDegrees[v - 1] += 1

    # Perform topological sorting.
    q = collections.deque([i for i, d in enumerate(inDegrees) if d == 0])

    while q:
      for _ in range(len(q)):
        u = q.popleft()
        n -= 1
        for v in graph[u]:
          inDegrees[v] -= 1
          if inDegrees[v] == 0:
            q.append(v)
      ans += 1

    return ans if n == 0 else -1
