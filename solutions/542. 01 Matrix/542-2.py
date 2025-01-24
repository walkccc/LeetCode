class Solution:
  def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(mat)
    n = len(mat[0])
    q = collections.deque()

    for i in range(m):
      for j in range(n):
        if mat[i][j] == 0:
          q.append((i, j))
        else:
          mat[i][j] = math.inf

    while q:
      i, j = q.popleft()
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if mat[x][y] <= mat[i][j] + 1:
          continue
        q.append((x, y))
        mat[x][y] = mat[i][j] + 1

    return mat
