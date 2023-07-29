class Solution:
  def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
    m = len(maze)
    n = len(maze[0])
    dirs = [0, 1, 0, -1, 0]
    ans = 0
    q = collections.deque([(entrance[0], entrance[1])])
    seen = {(entrance[0], entrance[1])}

    while q:
      ans += 1
      for _ in range(len(q)):
        i, j = q.popleft()
        for k in range(4):
          x = i + dirs[k]
          y = j + dirs[k + 1]
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if (x, y) in seen or maze[x][y] == '+':
            continue
          if x == 0 or x == m - 1 or y == 0 or y == n - 1:
            return ans
          q.append((x, y))
          seen.add((x, y))

    return -1
