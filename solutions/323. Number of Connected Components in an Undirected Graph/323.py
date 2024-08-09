class Solution:
  def countComponents(self, n: int, edges: List[List[int]]) -> int:
    ans = 0
    graph = [[] for _ in range(n)]
    seen = set()

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    def bfs(node: int, seen: Set[int]) -> None:
      q = collections.deque([node])
      seen.add(node)

      while q:
        u = q.pop()
        for v in graph[u]:
          if v not in seen:
            q.append(v)
            seen.add(v)

    for i in range(n):
      if i not in seen:
        bfs(i, seen)
        ans += 1

    return ans
