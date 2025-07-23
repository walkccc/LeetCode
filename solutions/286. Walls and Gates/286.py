class Solution:
  def wallsAndGates(self, rooms: list[list[int]]) -> None:
    DIRS = ((0, 1), (1, 0), (0, -1), (-1, 0))
    INF = 2**31 - 1
    m = len(rooms)
    n = len(rooms[0])
    q = collections.deque((i, j)
                          for i in range(m)
                          for j in range(n)
                          if rooms[i][j] == 0)

    while q:
      i, j = q.popleft()
      for dx, dy in DIRS:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if rooms[x][y] != INF:
          continue
        rooms[x][y] = rooms[i][j] + 1
        q.append((x, y))
