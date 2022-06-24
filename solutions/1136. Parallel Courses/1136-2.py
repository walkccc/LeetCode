class Solution:
  def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
    ans = 0
    graph = [[] for _ in range(n)]
    inDegree = [0] * n

    # build graph
    for a, b in relations:
      u = a - 1
      v = b - 1
      graph[u].append(v)
      inDegree[v] += 1

    # topology
    q = deque([i for i, d in enumerate(inDegree) if d == 0])

    while q:
      for _ in range(len(q)):
        u = q.popleft()
        n -= 1
        for v in graph[u]:
          inDegree[v] -= 1
          if inDegree[v] == 0:
            q.append(v)
      ans += 1

    return ans if n == 0 else -1
