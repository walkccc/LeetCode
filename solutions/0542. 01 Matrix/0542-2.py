class Solution:
  def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
    m = len(matrix)
    n = len(matrix[0])
    dirs = [0, 1, 0, -1, 0]

    q = deque()

    for i in range(m):
      for j in range(n):
        if matrix[i][j] == 0:
          q.append((i, j))
        else:
          matrix[i][j] = inf

    while q:
      i, j = q.popleft()
      for k in range(4):
        x = i + dirs[k]
        y = j + dirs[k + 1]
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if matrix[x][y] <= matrix[i][j] + 1:
          continue
        q.append((x, y))
        matrix[x][y] = matrix[i][j] + 1

    return matrix
