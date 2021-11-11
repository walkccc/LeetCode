class Solution:
  def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
    graph = [[] for _ in range(n)]
    inDegree = [0] * n
    q = deque()
    dist = time.copy()

    # build graph
    for u, v in relations:
      graph[u - 1].append(v - 1)
      inDegree[v - 1] += 1

    # topology
    for i, degree in enumerate(inDegree):
      if degree == 0:
        q.append(i)

    while q:
      u = q.popleft()
      for v in graph[u]:
        dist[v] = max(dist[v], dist[u] + time[v])
        inDegree[v] -= 1
        if inDegree[v] == 0:
          q.append(v)

    return max(dist)
