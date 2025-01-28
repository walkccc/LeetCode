class Solution:
  def maxStudents(self, seats: list[list[str]]) -> int:
    m = len(seats)
    n = len(seats[0])
    dirs = ((-1, -1), (0, -1), (1, -1), (-1, 1), (0, 1), (1, 1))
    seen = [[0] * n for _ in range(m)]
    match = [[-1] * n for _ in range(m)]

    def dfs(i: int, j: int, sessionId: int) -> int:
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if seats[x][y] != '.' or seen[x][y] == sessionId:
          continue
        seen[x][y] = sessionId
        if match[x][y] == -1 or dfs(*divmod(match[x][y], n), sessionId):
          match[x][y] = i * n + j
          match[i][j] = x * n + y
          return 1
      return 0

    def hungarian() -> int:
      count = 0
      for i in range(m):
        for j in range(n):
          if seats[i][j] == '.' and match[i][j] == -1:
            sessionId = i * n + j
            seen[i][j] = sessionId
            count += dfs(i, j, sessionId)
      return count

    return sum(seats[i][j] == '.'
               for i in range(m)
               for j in range(n)) - hungarian()
