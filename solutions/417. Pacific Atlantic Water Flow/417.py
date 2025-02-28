class Solution:
  def pacificAtlantic(self, heights: list[list[int]]) -> list[list[int]]:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(heights)
    n = len(heights[0])
    qP = collections.deque()
    qA = collections.deque()
    seenP = [[False] * n for _ in range(m)]
    seenA = [[False] * n for _ in range(m)]

    for i in range(m):
      qP.append((i, 0))
      qA.append((i, n - 1))
      seenP[i][0] = True
      seenA[i][n - 1] = True

    for j in range(n):
      qP.append((0, j))
      qA.append((m - 1, j))
      seenP[0][j] = True
      seenA[m - 1][j] = True

    def bfs(q: deque, seen: list[list[bool]]):
      while q:
        i, j = q.popleft()
        h = heights[i][j]
        for dx, dy in dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if seen[x][y] or heights[x][y] < h:
            continue
          q.append((x, y))
          seen[x][y] = True

    bfs(qP, seenP)
    bfs(qA, seenA)

    return [[i, j] for i in range(m) for j in range(n) if seenP[i][j] and seenA[i][j]]
