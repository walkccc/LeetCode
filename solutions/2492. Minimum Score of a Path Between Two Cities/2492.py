class Solution:
  def minScore(self, n: int, roads: List[List[int]]) -> int:
    ans = math.inf
    graph = [[] for _ in range(n + 1)]  # graph[u] := [(v, distance)]
    q = collections.deque([1])
    seen = {1}

    for u, v, distance in roads:
      graph[u].append((v, distance))
      graph[v].append((u, distance))

    while q:
      u = q.popleft()
      for v, d in graph[u]:
        ans = min(ans, d)
        if v in seen:
          continue
        q.append(v)
        seen.add(v)

    return ans
