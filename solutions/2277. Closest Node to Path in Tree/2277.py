class Solution:
  def closestNode(
      self,
      n: int,
      edges: list[list[int]],
      query: list[list[int]],
  ) -> list[int]:
    tree = [[] for _ in range(n)]
    dist = [[-1] * n for _ in range(n)]

    for u, v in edges:
      tree[u].append(v)
      tree[v].append(u)

    def fillDist(start: int, u: int, d: int) -> None:
      dist[start][u] = d
      for v in tree[u]:
        if dist[start][v] == -1:
          fillDist(start, v, d + 1)

    for i in range(n):
      fillDist(i, i, 0)

    def findClosest(u: int, end: int, node: int, ans: int) -> int:
      for v in tree[u]:
        if dist[v][end] < dist[u][end]:
          return findClosest(
              v, end, node, ans if dist[ans][node] < dist[v][node] else v)
      return ans

    return [findClosest(start, end, node, start)
            for start, end, node in query]
