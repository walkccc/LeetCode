class Solution:
  # Similar to 3341. Find Minimum Time to Reach Last Room I
  def minMoves(self, matrix: list[str]) -> int:
    if matrix[-1][-1] == '#':
      return -1

    teleportPositions = [[] for _ in range(26)]

    for i, row in enumerate(matrix):
      for j, c in enumerate(row):
        if c not in ('.', '#'):
          teleportPositions[ord(c) - ord('A')].append((i, j))

    return self._dijkstra(matrix, teleportPositions,
                          (0, 0), (len(matrix) - 1, len(matrix[0]) - 1))

  def _dijkstra(
      self,
      matrix: list[str],
      teleportPositions: list[list[tuple[int, int]]],
      src: tuple[int, int],
      dst: tuple[int, int],
  ) -> int:
    DIRS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    m = len(matrix)
    n = len(matrix[0])
    dist = [[math.inf] * n for _ in range(m)]
    seen = set()

    dist[0][0] = 0
    minHeap = [(dist[0][0], src)]  # (d, u)

    while minHeap:
      d, u = heapq.heappop(minHeap)
      if u == dst:
        return d
      i, j = u
      if d > dist[i][j]:
        continue
      c = matrix[i][j]
      if c.isupper() and c not in seen:
        seen.add(c)
        for x, y in teleportPositions[ord(c) - ord('A')]:
          if d < dist[x][y]:
            dist[x][y] = d
            heapq.heappush(minHeap, (d, (x, y)))
      for dx, dy in DIRS:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if matrix[x][y] == '#':
          continue
        if d + 1 < dist[x][y]:
          dist[x][y] = d + 1
          heapq.heappush(minHeap, (d + 1, (x, y)))

    return -1
