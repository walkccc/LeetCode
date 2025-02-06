class Solution:
  def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(mat)
    n = len(mat[0])
    q = collections.deque()
    seen = [[False] * n for _ in range(m)]

    for i in range(m):
      for j in range(n):
        if mat[i][j] == 0:
          q.append((i, j))
          seen[i][j] = True

    while q:
      i, j = q.popleft()
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if seen[x][y]:
          continue
        mat[x][y] = mat[i][j] + 1
        q.append((x, y))
        seen[x][y] = True

    return mat
