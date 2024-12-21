class Solution:
  def highestPeak(self, isWater: list[list[int]]) -> list[list[int]]:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(isWater)
    n = len(isWater[0])
    ans = [[-1] * n for _ in range(m)]
    q = collections.deque()

    for i in range(m):
      for j in range(n):
        if isWater[i][j] == 1:
          q.append((i, j))
          ans[i][j] = 0

    while q:
      i, j = q.popleft()
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if ans[x][y] != -1:
          continue
        ans[x][y] = ans[i][j] + 1
        q.append((x, y))

    return ans
