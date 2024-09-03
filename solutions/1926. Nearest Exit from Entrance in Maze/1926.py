class Solution:
  def nearestExit(self, maze: list[list[str]], entrance: list[int]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(maze)
    n = len(maze[0])
    ans = 0
    q = collections.deque([(entrance[0], entrance[1])])
    seen = {(entrance[0], entrance[1])}

    while q:
      ans += 1
      for _ in range(len(q)):
        i, j = q.popleft()
        for dx, dy in dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if (x, y) in seen or maze[x][y] == '+':
            continue
          if x == 0 or x == m - 1 or y == 0 or y == n - 1:
            return ans
          q.append((x, y))
          seen.add((x, y))

    return -1
