class Solution:
  def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
    m = len(mat)
    n = len(mat[0])
    dirs = [0, 1, 0, -1, 0]
    q = deque()
    seen = [[False] * n for _ in range(m)]

    for i in range(m):
      for j in range(n):
        if mat[i][j] == 0:
          q.append((i, j))
          seen[i][j] = True

    while q:
      i, j = q.popleft()
      for k in range(4):
        x = i + dirs[k]
        y = j + dirs[k + 1]
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if seen[x][y]:
          continue
        mat[x][y] = mat[i][j] + 1
        q.append((x, y))
        seen[x][y] = True

    return mat
