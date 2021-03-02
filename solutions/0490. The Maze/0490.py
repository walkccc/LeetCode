class Solution:
  def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
    m = len(maze)
    n = len(maze[0])
    dirs = [0, 1, 0, -1, 0]

    q = deque([(start[0], start[1])])
    seen = [[False] * n for _ in range(m)]
    seen[start[0]][start[1]] = True

    def isValid(x: int, y: int) -> bool:
      return 0 <= x < len(maze) and 0 <= y < len(maze[0]) and maze[x][y] == 0

    while q:
      i, j = q.popleft()
      for k in range(4):
        x = i
        y = j
        while isValid(x + dirs[k], y + dirs[k + 1]):
          x += dirs[k]
          y += dirs[k + 1]
        if seen[x][y]:
          continue
        if x == destination[0] and y == destination[1]:
          return True
        q.append((x, y))
        seen[x][y] = True

    return False
