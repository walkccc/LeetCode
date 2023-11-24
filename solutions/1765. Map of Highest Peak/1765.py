class Solution:
  def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
    m = len(isWater)
    n = len(isWater[0])
    dirs = [0, 1, 0, -1, 0]
    ans = [[-1] * n for _ in range(m)]
    q = collections.deque()

    for i in range(m):
      for j in range(n):
        if isWater[i][j] == 1:
          q.append((i, j))
          ans[i][j] = 0

    while q:
      i, j = q.popleft()
      for k in range(4):
        x = i + dirs[k]
        y = j + dirs[k + 1]
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if ans[x][y] != -1:
          continue
        ans[x][y] = ans[i][j] + 1
        q.append((x, y))

    return ans
