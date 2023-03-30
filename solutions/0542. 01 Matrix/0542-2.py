class Solution:
  def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
    m = len(mat)
    n = len(mat[0])
    dirs = [0, 1, 0, -1, 0]
    q = collections.deque()

    for i in range(m):
      for j in range(n):
        if mat[i][j] == 0:
          q.append((i, j))
        else:
          mat[i][j] = math.inf

    while q:
      i, j = q.popleft()
      for k in range(4):
        x = i + dirs[k]
        y = j + dirs[k + 1]
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if mat[x][y] <= mat[i][j] + 1:
          continue
        q.append((x, y))
        mat[x][y] = mat[i][j] + 1

    return mat
