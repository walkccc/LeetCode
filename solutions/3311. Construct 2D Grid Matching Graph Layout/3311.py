class Solution:
  def constructGridLayout(self, n: int, edges: list[list[int]]) -> list[list[int]]:
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    # Randomly choose a node with the minimum degree as the corner.
    corner = min(range(len(graph)), key=lambda x: len(graph[x]))

    seen = {corner}
    firstRow = self._getFirstRow(graph, corner, seen)
    cols = len(firstRow)
    rows = n // cols

    ans = [[0] * cols for _ in range(rows)]
    ans[0] = firstRow

    for i in range(1, rows):
      for j in range(cols):
        for v in graph[ans[i - 1][j]]:
          if v not in seen:
            ans[i][j] = v
            seen.add(v)
            break

    return ans

  def _getFirstRow(
      self,
      graph: list[list[int]],
      corner: int,
      seen: set[int]
  ) -> list[int]:
    cornerDegree = len(graph[corner])
    row = [corner]
    # Continue appending neighbors until we hit another corner.
    while len(row) == 1 or len(graph[row[-1]]) == cornerDegree + 1:
      # Sort neighbors by degree to prioritize smaller ones (shortest row built first).
      graph[row[-1]].sort(key=lambda x: len(graph[x]))
      for v in graph[row[-1]]:
        if v not in seen and len(graph[v]) in (cornerDegree, cornerDegree + 1):
          row.append(v)
          seen.add(v)
          break
    return row
