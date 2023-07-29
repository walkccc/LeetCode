class Solution:
  def wallsAndGates(self, rooms: List[List[int]]) -> None:
    kInf = 2**31 - 1
    m = len(rooms)
    n = len(rooms[0])
    dirs = [0, 1, 0, -1, 0]
    q = collections.deque()

    for i in range(m):
      for j in range(n):
        if rooms[i][j] == 0:
          q.append((i, j))

    while q:
      i, j = q.popleft()
      for k in range(4):
        x = i + dirs[k]
        y = j + dirs[k + 1]
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if rooms[x][y] != kInf:
          continue
        rooms[x][y] = rooms[i][j] + 1
        q.append((x, y))
